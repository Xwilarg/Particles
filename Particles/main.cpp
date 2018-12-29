#include <SFML/Graphics.hpp>
#include "ParticlesManager.hpp"

int main()
{
	constexpr int xWin = 400, yWin = 400;
	sf::RenderWindow window(sf::VideoMode(xWin, yWin), "Particles");
	Particles::ParticlesManager manager(sf::Vector2i(xWin, yWin));
	manager.AddSpawner(sf::Vector2i(100, 100))
		->SetColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}

	return 0;
}