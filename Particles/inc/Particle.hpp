#pragma once

# include <SFML/System/Vector2.hpp>
# include <SFML/Graphics/Color.hpp>
# include <chrono>

namespace Particles
{
	class Particle final
	{
	public:
		Particle(const sf::Vector2i &pos) noexcept;
		void Update() noexcept;
		void SetColor(sf::Color &&color) noexcept;
		void SetColor(const sf::Color &color) noexcept;
		void SetVelocity(float velocity) noexcept;
		const sf::Vector2f &GetPosition() const noexcept;
		const sf::Color &GetColor() const noexcept;

	private:
		sf::Vector2f _pos;
		float _velocity;
		float _speed;
		std::chrono::high_resolution_clock::time_point _startDeltaTime;
		sf::Color _color;
	};
}