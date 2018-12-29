#include <utility>
#include <cmath>
#include "Particle.hpp"

namespace Particles
{
	Particle::Particle(const sf::Vector2i &pos) noexcept
		: _pos(pos), _velocity(0.f), _speed(.01f),
		_startDeltaTime(std::chrono::high_resolution_clock::now()),
		_color(sf::Color::White)
	{ }

	void Particle::Update() noexcept
	{
		float deltaTime = (float)(std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - _startDeltaTime).count() / 1000.f);
		_pos = sf::Vector2f(
			_pos.x + (float)std::cos(_velocity) * deltaTime * _speed,
			_pos.y + (float)std::sin(_velocity) * deltaTime * _speed
		);
	}

	void Particle::SetColor(sf::Color &&color) noexcept
	{
		_color = std::move(color);
	}

	void Particle::SetColor(const sf::Color &color) noexcept
	{
		_color = color;
	}

	const sf::Vector2f &Particle::GetPosition() const noexcept
	{
		return (_pos);
	}

	const sf::Color &Particle::GetColor() const noexcept
	{
		return (_color);
	}
}