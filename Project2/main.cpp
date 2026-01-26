#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode({ 800, 600 }), "SFML 3.0 works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    Texture texture("pp.png");
    Sprite sprite(texture);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(sprite); // tu avais oublié de l'afficher
        window.display();
    }
    return 0;
}