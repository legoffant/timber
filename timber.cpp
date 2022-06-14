#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

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
	spriteBee.setTexture(textureBee);
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

	// Variable pour contrôler le temps lui-même
	sf::Clock clock;

	bool paused = true;


		while (window.isOpen()){
		
		/* 
		 **************************************
		 * Controler des evenements de fenetre
		 **************************************
		 */

			sf::Event event;
			while (window.pollEvent(event)){

				if (event.type == sf::Event::Closed)
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){

					window.close();
				}
				// Start the game
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

					paused = false;
				}
			}

		/* 
		 * ***************************
		 * Mettre à jour la scène 
		 * ***************************
		 */ 

			sf::Time dt = clock.restart();

					
			// Configurer the bee
			if (!beeActive){

				// How fast is the bee
				srand((int)time(0));
				beeSpeed = (rand() % 200) + 200;
				// How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			}
			else {
			// Move the bee
				spriteBee.setPosition(
						spriteBee.getPosition().x -
						(beeSpeed * dt.asSeconds()),
						spriteBee.getPosition().y);
			// Has the bee reached the left-hand edge of the screen?
				if (spriteBee.getPosition().x < -100){
					// Set it up ready to be a whole new bee next frame
					beeActive = false;
				}
			}
			
			// Manage the clouds
				// Cloud 1
			if (!cloud1Active){
				// How fast is the cloud
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);
				// How high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;
			}
			else {
				spriteCloud1.setPosition(
						spriteCloud1.getPosition().x +
						(cloud1Speed * dt.asSeconds()),
						spriteCloud1.getPosition().y);
				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud1.getPosition().x > 1920) {
					// Set it up ready to be a whole new cloud next frame
					cloud1Active = false;
				}
			}	
			
			// Cloud 2 
			if (!cloud2Active){
				// How fast is the cloud
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);
				// How high is the cloud
				srand((int)time(0) * 20);
				float height = (rand() % 150);
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;
			}
			else {
				spriteCloud2.setPosition(
						spriteCloud2.getPosition().x +
						(cloud2Speed * dt.asSeconds()),
						spriteCloud2.getPosition().y);
				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud2.getPosition().x > 1920) {
					// Set it up ready to be a whole new cloud next frame
					cloud2Active = false;
				}
			}

			// Cloud 3
			if (!cloud3Active){
				// How fast is the cloud
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);
				// How high is the cloud
				srand((int)time(0) * 30);
				float height = (rand() % 150);
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;
			}
			else {
				spriteCloud3.setPosition(
						spriteCloud3.getPosition().x +
						(cloud3Speed * dt.asSeconds()),
						spriteCloud3.getPosition().y);
				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud3.getPosition().x > 1920) {
					// Set it up ready to be a whole new cloud next frame
					cloud3Active = false;
				}
			}

	/*
		 * **************************
		 * Dessiner la scene
		 * **************************
		 */

        window.clear();
		
		// Dessine la scene du jeu 
		window.draw(spriteBackground);
        
		// Dessine les nuages
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		// Dessine l'arbre
		window.draw(spriteTree);

		// Dessine l'abeille
		window.draw(spriteBee);


		window.display();
    }

	return 0;
}
