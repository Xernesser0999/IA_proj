#include <SFML/Graphics.hpp>
#include <optional>

#include "Baker.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML window");

    sf::Font font("Pixellettersfull-BnJ5.ttf");
    sf::Text text(font);
    text.setString("TEST");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Regular | sf::Text::Underlined);

    // Load a sprite to display
    Baker test(0, 0, "pp.png");
    sf::Clock clock;
    // Start the game loop
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        // Process events
        while (const auto event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        test.update(dt);
        test.render(window);
        window.draw(text);
        // Update the window
        window.display();
    }
}