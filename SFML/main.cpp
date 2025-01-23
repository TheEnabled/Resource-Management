//@# Spritesheet
//Assets can be downloaded here:
//https://opengameart.org/content/chiken-animation

//@! Spritesheets [01]
//A spritesheet is collection of sprites that can be used to create
//animations. Typically these sprites are arranged in a gird manner.
//@!e

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 640, 480 }), "Sprite sheet!");
    window.setFramerateLimit(60);

    //@! Loading the sprite [02a]
    //The sprite should first be loaded into a texture. This process is
    //the same as loading a texture for a sprite. However, this loads
    //the entire image to the texture. Only a segment of the texture is
    //to be shown at a time.
    sf::Texture texture1;
    if (!texture1.loadFromFile("chicken.png")) return 1;

    //@! Getting the sprite location [02b]
    //To load a smaller section of the texture, the exact location inside
    //the sprite should be located. This means getting a starting location
    //and a width and height of the location within the texture.
    sf::Vector2u texSize = texture1.getSize();
    int sp_w = texSize.x / 4;
    int sp_h = texSize.y / 4;
    sf::IntRect spriteRec({ 0,0 }, { sp_w,sp_h });

    //@! Getting the sprite location [02c]
    //Once the location of the rectangle is found, the rectangle is fed to
    //the sprite along with the texture. Note that this position is different
    //from the position of the sprite.
    sf::Sprite sprite1(texture1, spriteRec);
    sprite1.setPosition({ 100.f, 100.f });
    //@!e

    int spriteFrame = 0;
    int time = 0;
    bool isAnimate = true;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }//end while

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            isAnimate = true;
            spriteFrame = 0;
        }

        //@! Updating Animation [03]
        //To update the animation, the texture rectangle should be updated
        //to an updated location. This will now adjust the image being
        //shown by the sprite.
        time++;
        if (isAnimate && time >= 20) {
            time = 0;   spriteFrame++;
            spriteRec.position.x = spriteFrame % 4 * sp_w;
            spriteRec.position.y = spriteFrame / 4 * sp_h;
            sprite1.setTextureRect(spriteRec);
            if (spriteFrame == 15) {
                isAnimate = false;
            }
        }
        //@!e

        window.clear();
        if (isAnimate)
            window.draw(sprite1);
        window.display();
    }
    return 0;
}