#pragma once

#include <vector>
#include "Scene.h"
#include

class Menu : public Scene
{
private:

public:

    Menu(sf::RenderWindow& window);
    ~Menu();

    void createGameObjects();
    void displayScene(sf::RenderWindow& window) override;
    void update(const bool* keys, float dt);
    void nextScene(SceneState& currentScene, keys* _myKeys) override;
};