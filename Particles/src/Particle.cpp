#include <utility>
#include "Particle.hpp"

namespace Particles
{
	Particle::Particle(const sf::Vector2i &pos) noexcept
		: _pos(pos), _velocity(0.f, 0.f)
	{ }
}