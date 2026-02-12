#include "Morning.h"

std::vector<GameObjects*> Morning::StaticDrawble = {};

Morning::Morning(sf::RenderWindow& window) : textclock(fonta) {
    bg = new sf::RectangleShape();
    createGameObjects();
    spawnTimer = 0.0f;
    spawnClock = Clock(true); 
}

Morning::~Morning() {
    for (auto* npcBlackboard : npcBlackboards) {
        delete npcBlackboard;
    }
    npcBlackboards.clear();
    for (auto* npcBt : npcBehaviorTrees) {
        delete npcBt;
    }
    npcBehaviorTrees.clear();
    for (auto* npc : npcs) {
        delete npc;
    }
    npcs.clear();

    delete TX;
    delete rectangle;
    TX = nullptr;
    rectangle = nullptr;
}

void Morning::clearlevel() {
    for (auto* npcBlackboard : npcBlackboards) {
        delete npcBlackboard;
    }
    npcBlackboards.clear();
    for (auto* npcBt : npcBehaviorTrees) {
        delete npcBt;
    }
    npcBehaviorTrees.clear();
    for (auto* npc : npcs) {
        delete npc;
    }
    npcs.clear();
    StaticDrawble.clear();
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

    timer = 15;
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
    for (auto* npc : npcs) {
        npc->render(window);
    }
    for (auto& StaticDraw : StaticDrawble) {
        if (StaticDraw != nullptr) {
            StaticDraw->renderGameObject(window);
        }
    }
    window.draw(*rectangle);
    window.draw(textclock);
}


void Morning::update(const bool* keys, float dt) {
    bakery->updateGameObject(dt);
    store->updateGameObject(dt);
    candy_shop->updateGameObject(dt);

    float elapsed = spawnClock.getElapsedTime();
    spawnTimer += elapsed;

    if (spawnTimer >= spawnInterval) {
        spawnNpc();
        spawnTimer = 0.0f; 
    }

    StaticDrawble.erase( std::remove(StaticDrawble.begin(), StaticDrawble.end(), nullptr), StaticDrawble.end());

    for (size_t i = 0; i < npcs.size(); ++i) {
        npcBehaviorTrees[i]->tick(dt);
        npcs[i]->update(dt, bakery);
    }
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

void Morning::spawnNpc() {
    Npc* newNpc = new Npc(0, 800, 100, 100, 300.0f, "sprite/player.png");
    NpcBlackBoard* npcBlackboard = new NpcBlackBoard();
	int random = rand() % 3;
	int randomXShop = rand() % 100 + 250;
    npcBlackboard->coorNpcX = newNpc->posX;
    npcBlackboard->coorNpcY = newNpc->posY;
    npcBlackboard->shopCoorX = shops[random]->pos.x + shops[random]->size.x - randomXShop;
    npcBlackboard->shopCoorY = shops[random]->pos.y + shops[random]->size.y - 100;
    newNpc->bt = npcBlackboard;

    NpcBehaviourTree* npcBt = new NpcBehaviourTree(newNpc);
    npcBt->buildTree();
    npcBt->setBlackboard(npcBlackboard);
    npcBt->execute();

    npcs.push_back(newNpc);
    npcBlackboards.push_back(npcBlackboard);
    npcBehaviorTrees.push_back(npcBt);
}
