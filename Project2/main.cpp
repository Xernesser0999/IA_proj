#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML window");

    // Load a sprite to display
    const sf::Texture texture("pp.png");
    sf::Sprite sprite(texture);

    // Start the game loop
    while (window.isOpen())
    {
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
        window.draw(sprite);

        // Update the window
        window.display();
    }
}