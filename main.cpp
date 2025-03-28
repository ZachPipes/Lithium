#include <SFML/Graphics.hpp>

#include "world.h"

int main() {
    // Creating the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Lithium");

    // Creating the world
    World world;

    // Game loop
    while(window.isOpen()) {
        std::optional<sf::Event> event = window.pollEvent();

        if(event) {
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(); // Clears previous frame

        world.draw(window); // Draws world

        window.display(); // Displays the current frame
    }

    return 0;
}
