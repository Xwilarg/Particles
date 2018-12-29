#include <iostream>
#include "ParticlesManager.hpp"

namespace Particles
{
	ParticlesManager::ParticlesManager(sf::Vector2i &&winSize) noexcept
		: _winSize(std::move(winSize)), _particles(), _image(),
		_texture(), _sprite()
	{ }

	std::unique_ptr<Spawner> &ParticlesManager::AddSpawner(sf::Vector2i &&pos) noexcept
	{
		_spawners.push_back(std::make_unique<Spawner>(*this, std::move(pos)));
		return (_spawners.back());
	}

	std::unique_ptr<Particle> &ParticlesManager::AddParticle(const sf::Vector2i &pos) noexcept
	{
		_particles.push_back(std::make_unique<Particle>(pos));
		return (_particles.back());
	}

	void ParticlesManager::Update() noexcept
	{
		for (auto &spawner : _spawners)
			spawner->Update();
		_image.create(_winSize.x, _winSize.y);
		for (auto &particle : _particles)
		{
			particle->Update();
			const sf::Vector2f &pos = particle->GetPosition();
			_image.setPixel((int)pos.x, (int)pos.y, sf::Color::White);
		}
		_texture.update(_image);
		_sprite.setTexture(_texture);
	}

	void ParticlesManager::Draw(sf::RenderWindow &window) const noexcept
	{
		window.draw(_sprite);
	}
}