#include <utility>
#include "Spawner.hpp"

namespace Particles
{
	Spawner::Spawner(sf::Vector2i &&pos) noexcept
		: _pos(std::move(pos)), _color(sf::Color::White)
	{ }

	void Spawner::Update() noexcept
	{ }

	void Spawner::SetColor(sf::Color &&color) noexcept
	{
		_color = color;
	}

	void Spawner::SetColor(const sf::Color &color) noexcept
	{
		_color = color;
	}
}