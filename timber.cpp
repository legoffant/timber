#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Commencer le jeu dans la fonction main

int main() {
	
	
	// Creer un objet "vm" mode video de 1920x1080
	sf::VideoMode vm(1920, 1080);

	// Creer et ouvrir une fenetre pour le jeu timber!
	sf::RenderWindow window(vm, "Timber!");

	// Créer une texture pour le graphisme du GPU
	sf::Texture textureBackground;
	// Charger un graphisme depuis la texture
	textureBackground.loadFromFile("graphics/sprite_Background.png");
	// Créer un sprite
	sf::Sprite spriteBackground;
	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);
	// Paramêtrer le background pour qu'il prenne tout l'écran
	spriteBackground.setPosition(0,0);

	// Make a tree sprite
	sf::Texture textureTree;
	textureTree.loadFromFile("graphics/sprite_MainTree.png");
	sf::Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Prepare the bee
	sf::Texture textureBee;
	textureBee.loadFromFile("graphics/sprite_Bee.png");
	sf::Sprite spriteBee;
	spriteBee.setTexture(textureTree);
	spriteBee.setPosition(0, 800);

	// Es-ce que the bee est t-elle en train de bouger
	bool beeActive = false;

	// A quel vitesse vol the bee
	float beeSpeed = 0.0f;

	// Mettre 3 nuages à partir de la texture
	sf::Texture textureCloud;

	// Charger la texture cloud
	textureCloud.loadFromFile("graphics/sprite_Cloud.png");

	// 3 sprites avec la même texture
	sf::Sprite spriteCloud1, spriteCloud2, spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	
	// Positioner les nuages
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);

	// Es-ce que les nuages sont en ce moment à l'écran?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	// Comment sont rapide les nuages
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		
		// Dessine la scene du jeu 
		window.draw(spriteBackground);
        
		window.display();
    }

	return 0;
}
