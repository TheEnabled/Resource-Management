#include <SFML/Graphics.hpp>
#include <iostream>

//test

int main() {
    sf::RenderWindow window(sf::VideoMode({ 512, 512 }), "Sol Tabboga");
    window.setFramerateLimit(60);

    sf::Texture crabtexture;
    sf::Texture bgtexture;

    if (!bgtexture.loadFromFile("bg.png")) return 1;

    sf::Sprite bg(bgtexture);

    if (!crabtexture.loadFromFile("crab.png")) return 1;
    sf::Sprite crab(crabtexture);

    crab.setPosition(sf::Vector2f(0.f, 0.f));
    crab.scale(sf::Vector2f(0.1f, 0.1f));

    bg.setPosition(sf::Vector2f(0.f, 0.f));
    bg.scale(sf::Vector2f(1.f, 1.f));

    const float gridSize = 50.f; // Size of a grid step

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Up)
                    crab.move({ 0.f, -gridSize });
                else if (keyPressed->code == sf::Keyboard::Key::Left)
                    crab.move({ -gridSize, 0.f });
                else if (keyPressed->code == sf::Keyboard::Key::Down)
                    crab.move({ 0.f, gridSize });
                else if (keyPressed->code == sf::Keyboard::Key::Right)
                    crab.move({ gridSize, 0.f });


                // Debug output
                std::cout << "Position: ("
                    << crab.getPosition().x << ", "
                    << crab.getPosition().y << ")" << std::endl;
            }
        }

        window.clear();
        window.draw(bg);
        window.draw(crab);
        window.display();
    }
    return 0;
}
