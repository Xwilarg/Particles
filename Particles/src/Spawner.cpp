#include <utility>
#include <chrono>
#include "Spawner.hpp"
#include "ParticlesManager.hpp"

namespace Particles
{
	Spawner::Spawner(ParticlesManager &manager, sf::Vector2i &&pos) noexcept
		: _pos(std::move(pos)), _color(sf::Color::White), _manager(manager),
		_startTime(std::chrono::high_resolution_clock::now())
	{ }

	void Spawner::Update() noexcept
	{
		if (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - _startTime).count() > 100)
		{
			_manager.AddParticle(_pos)
				->SetColor(_color);
			_startTime = std::chrono::high_resolution_clock::now();
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
}