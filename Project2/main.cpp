#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

#include "Scene.h"
#include "SceneManager.h"
#include "Baker.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML window");
    SceneManager scene(window);

    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        while (const auto event = window.pollEvent())
        {
            scene.displayState(window);
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        scene.updateState(nullptr, dt);

        window.clear();
        scene.displayState(window);
        window.display();
    }
}