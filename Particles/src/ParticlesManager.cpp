#include <iostream>
#include "ParticlesManager.hpp"

namespace Particles
{
	ParticlesManager::ParticlesManager(sf::Vector2i &&winSize) noexcept
		: _winSize(std::move(winSize)), _particles(), _image(), _penImage(),
		_texture(), _sprite(), _penSize(10)
	{
		_texture.create(winSize.x, winSize.y);
		_penImage.create(winSize.x, winSize.y);
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
		_image.create(_winSize.x, _winSize.y, _penImage.getPixelsPtr());
		for (int i = static_cast<int>(_particles.size() - 1); i >= 0; i--)
		{
			if (!_particles[i]->Update(_penImage, *this))
			{
				_particles.erase(_particles.begin() + i);
				continue;
			}
			const sf::Vector2i &pos = static_cast<sf::Vector2i>(_particles[i]->GetPosition());
			if (_image.getPixel(pos.x, pos.y) == sf::Color::White)
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

	void ParticlesManager::DrawWall(const sf::Vector2i &mousePos, bool addWall) noexcept
	{
		sf::Color color = (addWall) ? (sf::Color::White) : (sf::Color::Black);
		for (int i = -_penSize, y = 0; i <= 0; i++, y++)
		{
			for (int yTmp = y; yTmp >= -y; yTmp--)
			{
				sf::Vector2i pos(mousePos.x + i, mousePos.y + yTmp);
				if (DoesPointExist(pos))
					_penImage.setPixel(pos.x, pos.y, color);
			}
			for (int yTmp = y; yTmp >= -y; yTmp--)
			{
				sf::Vector2i pos(mousePos.x - i, mousePos.y + yTmp);
				if (DoesPointExist(pos))
					_penImage.setPixel(pos.x, pos.y, color);
			}
		}
	}

	bool ParticlesManager::DoesPointExist(const sf::Vector2i &pos) const noexcept
	{
		return (pos.x >= 0 && pos.x < _winSize.x && pos.y >= 0 && pos.y < _winSize.y);
	}
}