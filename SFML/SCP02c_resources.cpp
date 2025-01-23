//@# Game Resources

//@! Texture Packer [01a]
//In environments where memory is to be optimized, texture packers can
//be used to put all textures of a game into one image and have all
//sprites refer to this one texture. In this example, the GDX texture
//packer is used but there are other texture packers.
//. https://github.com/crashinvaders/gdx-texture-packer-gui
//. https://www.codeandweb.com/texturepacker/tutorials/how-to-create-a-sprite-sheet

//@! Texture Atlas [01b]
//Once a texture packer is used to process the assets, a single image is
//created that could contain all the assets. Optimizations can be applied to
//the generated image. An Atlas is also created which will indicate the
//locations of specific textures on the larger image.
//. In this example, assets form candy pack 1 are used:
//. https://opengameart.org/content/candy-pack-1

//@! Texture Atlas Reader [01c]
//To properly use the texture atlas, a reader should be created. Since texture
//atlases are typically text files, a parser is easy to develop. In this
//example two atlas reader were made which looks at the atlas created by
//the GDX texture packer.
//. AtlasParserM - atexture atlas reader written by hand.
//. AtlasParserGPT - a texture atlas reader generated by chatgpt but cleaned-up manually.
//@!e

#include <iostream>
#include "AtlasParserM.h"

//@! Resource Manager [02a]
//A resource manager can be used to facilitate the use of a texture atlas.
//A singleton may be used to make the resources easily accessible thoughout
//the program.
class GameResources{
    //@! Resource Manager creation [02b]
    //Should a singleton be used, the resource manager should have static
    //instance and will load the texture and atlas upon its creation.
	private:
		static GameResources* myInstance;   
		sf::Texture texture;
		std::unordered_map<std::string,sf::IntRect>* atlas;
		GameResources(){
		    if(texture.loadFromFile("sweetpack.png"))
		        atlas = createDictionary();
		}
    //@! Resource Manager instance [02c]
    //Once the resource manager is created, it only returns pointers of
    //its information. It does not return the actual object as the
    //pointer should be shared through-out all the parts thats use
    //the resources.
	public:
		static GameResources* createInstance(){
            if(myInstance == nullptr)
                myInstance = new GameResources();
            return myInstance;
        }
		std::unordered_map<std::string,sf::IntRect>* getAtlas(){ return atlas; }
		sf::Texture* getTexture(){ return &texture; }
    //@!e
};


GameResources* GameResources::myInstance = nullptr;

int main() {
    sf::RenderWindow window(sf::VideoMode({640, 480}), "Atlas!");
    window.setFramerateLimit(60);
    
    //@! Using the Resource Manager [03]
    //The resources can be used to obtain the texure and location of
    //the images without the need of creating multiple instances of the
    //same texture.
    GameResources* res = GameResources::createInstance();
    sf::Texture* tex = res->getTexture();
    std::unordered_map<std::string,sf::IntRect>* atlas = res->getAtlas();
    
    sf::Sprite sprite1(*tex, (*atlas)["heart_blue"]);
    sprite1.setPosition({100.f, 100.f});
    sf::Sprite sprite2(*tex, (*atlas)["jelly_yellow"]);
    sprite2.setPosition({200.f, 200.f});
    sf::Sprite sprite3(*tex, (*atlas)["lollipop_red"]);
    sprite3.setPosition({300.f, 100.f});
    //@!e
    


    while (window.isOpen()){
        while(const std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>())
                window.close();
        }//end while
        
        window.clear();
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.display();
    }
    delete res;
    return 0;
}

