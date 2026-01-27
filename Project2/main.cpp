#include <SFML/Graphics.hpp>
#include <optional>

#include "Baker.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML window");

    Baker test(0, 0, "pp.png");
    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        test.update(dt);
        test.render(window);

        window.display();
    }
}