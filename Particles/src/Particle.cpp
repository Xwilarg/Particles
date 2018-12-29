#include <utility>
#include <cmath>
#include "ParticlesManager.hpp"
#include "Particle.hpp"

namespace Particles
{
	Particle::Particle(const sf::Vector2i &pos) noexcept
		: _pos(pos), _velocity(0.f), _speed(.01f),
		_startDeltaTime(std::chrono::high_resolution_clock::now()),
		_color(sf::Color::White)
	{ }

	bool Particle::Update(const sf::Image &_penImage, ParticlesManager &manager) noexcept
	{
		float deltaTime = (float)(std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - _startDeltaTime).count() / 1000.f);
		float newXPos = _pos.x + static_cast<float>(std::cos(_velocity)) * deltaTime * _speed;
		float newYPos = _pos.y + static_cast<float>(std::sin(_velocity)) * deltaTime * _speed;
		sf::Vector2i newPosInt(static_cast<int>(newXPos), static_cast<int>(newYPos));
		if (!manager.DoesPointExist(newPosInt))
			return (false);
		if (_penImage.getPixel(newPosInt.x, newPosInt.y) != sf::Color::White)
			_pos = sf::Vector2f(newXPos, newYPos);
		else if (_penImage.getPixel(newPosInt.x, static_cast<int>(_pos.y)) != sf::Color::White)
			_pos = sf::Vector2f(newXPos, _pos.y);
		else if (_penImage.getPixel(static_cast<int>(_pos.x), newPosInt.y) != sf::Color::White)
			_pos = sf::Vector2f(_pos.x, newYPos);
		else
			_pos = sf::Vector2f(_pos.x, _pos.y);
		return (true);
	}

	void Particle::SetColor(sf::Color &&color) noexcept
	{
		_color = std::move(color);
	}

	void Particle::SetVelocity(float velocity) noexcept
	{
		_velocity = velocity;
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