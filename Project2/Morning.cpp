#include "Morning.h"

Morning::Morning(sf::RenderWindow& window) : textclock(fonta) {
    bg = new sf::RectangleShape();
    createGameObjects();
    spawnTimer = 0.0f;
    spawnClock = Clock(true); 
}

Morning::~Morning() {

    delete TX;
    delete rectangle;
    TX = nullptr;
    rectangle = nullptr;
}

void Morning::clearlevel() {

    delete TX;
    delete rectangle;
    TX = nullptr;
    rectangle = nullptr;
}

void Morning::setImages(sf::RectangleShape* myRect, const char* path, float x, float y, float w, float h) {
    sf::Texture* tex = new sf::Texture(path);
    vecTex.push_back(tex);
    myRect->setPosition({ x,y });
    myRect->setSize({ w,h });
    myRect->setTexture(tex);
}

void Morning::createGameObjects() {
    setImages(bg, "sprite/ground.png", 0, 0, 1920, 1080);


    bakery = new Bakery(0, 0, 450, 400);
	shops.push_back(bakery);
    store = new Store(450, 0, 420, 400);
    shops.push_back(store);
    candy_shop = new CandyShop(900, 0, 400, 400);
    shops.push_back(candy_shop);

    btClock = Clock(true);
    TX = new sf::Texture();
    TX->loadFromFile("sprite/Clock_morning.png");

    rectangle = new sf::RectangleShape(size);
    rectangle->setPosition(pos);
    rectangle->setTexture(TX);

    timer = 5;
    startPoint = 0;

    fonta.openFromFile("Pixellettersfull-BnJ5.ttf");
    textclock.setFont(fonta);
    textclock.setString("Day " + std::to_string(Day_number));
    textclock.setCharacterSize(48);
    textclock.setFillColor(sf::Color::White);
    textclock.setPosition({ 1920 - 200, 5 });
}

void Morning::displayScene(sf::RenderWindow& window) {
    window.draw(*bg);
    store->renderGameObject(window);
    bakery->renderGameObject(window);
    candy_shop->renderGameObject(window);
    window.draw(*rectangle);
    window.draw(textclock);
}


void Morning::update(const bool* keys, float dt) {
    bakery->updateGameObject(dt);
    store->updateGameObject(dt);
    candy_shop->updateGameObject(dt);

    float elapsed = spawnClock.getElapsedTime();
    spawnTimer += elapsed;

    startPoint += dt;

    if (startPoint >= timer) {
        daypass = true;
        startPoint = 0;
    }
}

void Morning::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
        currentScene = SceneState::menu;
    }

    if (daypass == true) {
        daypass = false;
        Day_number += 1;
        textclock.setString("Day " + std::to_string(Day_number));
        clearlevel();
        createGameObjects();
        currentScene = day;
    }
}


