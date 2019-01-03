#include <utility>
#include <chrono>
#include <cstdlib>
#include "Spawner.hpp"
#include "ParticlesManager.hpp"

namespace Particles
{
	Spawner::Spawner(ParticlesManager &manager, sf::Vector2i &&pos) noexcept
		: _pos(std::move(pos)), _color(sf::Color::White), _manager(manager),
		_clock(), _spawnRate(100.0)
	{ }

	void Spawner::Update() noexcept
	{
		if (_clock.getElapsedTime().asMilliseconds() > _spawnRate)
		{
			auto& particle = _manager.AddParticle(_pos);
			particle->SetColor(_color);
			particle->SetVelocity(static_cast<float>(rand() / (2.0 * 3.1415)));
			_clock.restart();
		}
	}

	void Spawner::SetColor(sf::Color &&color) noexcept
	{
		_color = color;
	}

	void Spawner::SetColor(const sf::Color &color) noexcept
	{
		_color = color;
	}

	void Spawner::SetSpawnRate(double spawnRate) noexcept
	{
		_spawnRate = spawnRate;
	}
}