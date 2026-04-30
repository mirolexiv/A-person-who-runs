#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{

	float CurrentFrame = 0;
    RenderWindow window(VideoMode({ 1800, 1000 }), "A person who walks");
	window.setFramerateLimit(120);
	float speed = 4;

    Image image;
    if (!image.loadFromFile("perconag.png"))
        return -1;

    Texture texture;
    if (!texture.loadFromImage(image))
        return -1;

    Sprite sprite(texture);

    sprite.setPosition({ 0, 0 });
    sprite.setTextureRect(IntRect({ 0, 0 }, { 307, 384 }));
    sprite.setScale({ 0.7f, 0.7f });
	Clock clock;
	float koeficint = 0.007;

    while (window.isOpen())
    {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 600;
		        
        while (auto event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }

		if (Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
			CurrentFrame += koeficint * time;
            if (CurrentFrame > 9) { CurrentFrame -= 9; }
            sprite.setTextureRect(IntRect({ int (CurrentFrame) * 307, 0 }, { 304, 390 }));
			sprite.move({ speed, 0 });
        }
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            CurrentFrame += koeficint * time;
            if (CurrentFrame > 9) { CurrentFrame -= 9; }
            sprite.setTextureRect(IntRect({ 2463 - int(CurrentFrame) * 307, 395 }, { 300, 390 }));
            sprite.move({ -speed, 0 });
        }
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            CurrentFrame += koeficint * time;
            if (CurrentFrame > 9) { CurrentFrame -= 9; }
            sprite.setTextureRect(IntRect({ int(CurrentFrame) * 307, 1156 }, { 307, 390 }));
            sprite.move({ 0, -speed/3 });
        }
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            CurrentFrame += koeficint * time;
            if (CurrentFrame > 9) { CurrentFrame -= 9; }
            sprite.setTextureRect(IntRect({ int(CurrentFrame) * 307, 771 }, { 307, 390 }));
            sprite.move({ 0, speed/3 });
        }

        window.clear(Color(194, 214, 214));
        window.draw(sprite);
        window.display();
    }

    return 0;
}