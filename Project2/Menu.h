#pragma once

#include <vector>
#include "Scene.h"
#include "Morning.h"
#include "GUI_button.h"

class Menu : public Scene {
public:

    Menu(sf::RenderWindow& window);
    ~Menu();

    void createGameObjects() ;
    void displayScene(sf::RenderWindow& window) override;
    void update(const bool* keys, float dt);
    void nextScene(SceneState& currentScene, keys* _myKeys) override;
};