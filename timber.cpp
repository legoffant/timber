#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Commencer le jeu dans la fonction main

int main() {
	
	// Creer un objet "vm" mode video de 1920x1080
	sf::VideoMode vm(1920, 1080);

	// Creer et ouvrir une fenetre pour le jeu timber!
	sf::RenderWindow windows(vm, "Timber!", sf::Style::Fullscreen);

	return 0;
}
