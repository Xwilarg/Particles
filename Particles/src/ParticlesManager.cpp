#include <iostream>
#include "ParticlesManager.hpp"

namespace Particles
{
	ParticlesManager::ParticlesManager(sf::Vector2i &&winSize) noexcept
		: _winSize(std::move(winSize)), _particles(), _image(),
		_texture(), _sprite()
	{
		_texture.create(winSize.x, winSize.y);
	}

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
		for (int i = static_cast<int>(_particles.size() - 1); i >= 0; i--)
		{
			_particles[i]->Update();
			const sf::Vector2f &pos = _particles[i]->GetPosition();
			if (pos.x < 0 || pos.x >= _winSize.x || pos.y < 0 || pos.y >= _winSize.y)
				_particles.erase(_particles.begin() + i);
			else
				_image.setPixel(pos.x, pos.y, _particles[i]->GetColor());
		}
		_texture.update(_image);
		_sprite.setTexture(_texture);
	}

	void ParticlesManager::Draw(sf::RenderWindow &window) const noexcept
	{
		window.draw(_sprite);
	}
}