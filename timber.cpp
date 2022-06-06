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

	    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

	return 0;
}
