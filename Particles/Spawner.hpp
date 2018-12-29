#pragma once

# include <SFML/System/Vector2.hpp>
# include <SFML/Graphics/Color.hpp>

namespace Particles
{
	class Spawner
	{
	public:
		Spawner(sf::Vector2i &&pos) noexcept;
		void Update() noexcept;
		void SetColor(sf::Color &&color) noexcept;
		void SetColor(const sf::Color &color) noexcept;

	private:
		sf::Vector2i _pos;
		sf::Color _color;
	};
}