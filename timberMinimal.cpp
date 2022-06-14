#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main() {
	
	//Create a video mode object
	sf::VideoMode vm(1920, 1080);

	//Create and open windows for the game
	sf::RenderWindow window(vm, "Timber!", sf::Style::Fullscreen);

	while (window.isOpen()) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

			window.close();
		}

		window.clear();

		window.display();

	}
	return 0;

}
