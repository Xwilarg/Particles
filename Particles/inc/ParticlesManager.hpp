#pragma once

# include <vector>
# include <memory>

# include "Particle.hpp"
# include "Spawner.hpp"

namespace Particles
{
	class ParticlesManager final
	{
	public:
		ParticlesManager(sf::Vector2i &&winSize) noexcept;
		std::unique_ptr<Spawner> &AddSpawner(sf::Vector2i &&pos) noexcept;
		std::unique_ptr<Particle> &AddParticle(const sf::Vector2i &pos) noexcept;
		void Update() noexcept;

	private:
		const sf::Vector2i _winSize;
		std::vector<std::unique_ptr<Particle>> _particles;
		std::vector<std::unique_ptr<Spawner>> _spawners;
	};
}