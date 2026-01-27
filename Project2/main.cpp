#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML window");

    const sf::Texture texture("pp.png");
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        window.draw(sprite);

        window.display();
    }
}