#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(5, 5);
	quad[1].position = sf::Vector2f(200, 5);
	quad[2].position = sf::Vector2f(200, 200);
	quad[3].position = sf::Vector2f(5, 200);

	sf::Texture texture;

	if (!texture.loadFromFile("texture.jpeg"))
	{
		std::cout << "ERROR" << std::endl;
	}

	quad[0].texCoords = sf::Vector2f(0, 0);
	quad[1].texCoords = sf::Vector2f(50, 0);
	quad[2].texCoords = sf::Vector2f(50, 100);
	quad[3].texCoords = sf::Vector2f(0, 100);

	sf::Transform transform;

	transform.rotate(45, sf::Vector2f(100, 100));

	sf::RenderStates states;
	states.transform = transform;
	states.texture = &texture;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		window.draw(quad, states);

		window.display();
	}
}