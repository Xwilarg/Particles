#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "ParticlesManager.hpp"

int main()
{
	srand(time(0));
	constexpr int xWin = 400, yWin = 400;
	sf::RenderWindow window(sf::VideoMode(xWin, yWin), "Particles");
	Particles::ParticlesManager manager(sf::Vector2i(xWin, yWin));

	auto &spawner1 = manager.AddSpawner(sf::Vector2i(100, 100));
	spawner1->SetColor(sf::Color::Red);
	spawner1->SetSpawnRate(1.0);

	auto &spawner2 = manager.AddSpawner(sf::Vector2i(150, 150));
	spawner2->SetColor(sf::Color::Blue);
	spawner2->SetSpawnRate(1.0);

	auto &spawner3 = manager.AddSpawner(sf::Vector2i(300, 300));
	spawner3->SetColor(sf::Color::Green);
	spawner3->SetSpawnRate(1.0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		manager.Update();
		manager.Draw(window);
		window.display();
	}

	return 0;
}