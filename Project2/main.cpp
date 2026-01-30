#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

#include "Baker.h"
#include "SceneManager.h"
#include "KeyStruct.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML window");
    SceneManager sM = SceneManager(window);
    keys myKeys;



    // Load a sprite to display
    Baker test(0, 0, "pp.png");
    sf::Clock clock;
    
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        while (const auto event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        myKeys.initKeys(myKeys.myKeys);
        sM.manageState(&myKeys, window);
        sM.updateState(myKeys.myKeys, dt, window);

        window.clear();

        sM.displayState(window);

        window.display();
    }
}