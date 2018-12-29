#include "ParticlesManager.hpp"

namespace Particles
{
	ParticlesManager::ParticlesManager(sf::Vector2i &&winSize) noexcept
		: _winSize(std::move(winSize)), _particles()
	{ }

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
	}
}