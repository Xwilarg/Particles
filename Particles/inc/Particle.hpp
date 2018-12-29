#pragma once

# include <SFML/System/Vector2.hpp>

namespace Particles
{
	class Particle final
	{
	public:
		Particle(sf::Vector2i &&pos) noexcept;

	private:
		sf::Vector2i _pos;
		sf::Vector2f _velocity;
	};
}