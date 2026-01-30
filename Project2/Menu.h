#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include <vector>
#include "Scene.h"
#include "GUI_button.h"

class Menu : public Scene{
private:

public:
    GUI_button* button;
    GUI_button* Quit_button;

public:

    Menu(sf::RenderWindow& window);
    ~Menu();

    void createGameObjects();
    void displayScene(sf::RenderWindow& window) override;
    void update(const bool* keys, float dt, sf::RenderWindow& window);
    void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;
};