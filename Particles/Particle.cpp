#include <utility>
#include "Particle.hpp"

namespace Particles
{
	Particle::Particle(sf::Vector2i &&pos) noexcept
		: _pos(std::move(pos)), _velocity(0.f, 0.f)
	{ }
}