#include <iostream>
#include <SFML/Graphics.hpp>

#include "entity.h"
#include "TextureManager.h"
#include "world.h"

int main() {
    TextureManager::loadTextures();

    // Creating the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Lithium");

    // Creating the world
    World world(20,15);

    // Creating an entity
    Entity man(7, 5, TextureManager::manTexture);

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

        if(isKeyPressed(sf::Keyboard::Key::W)) {
            std::cout << "MOVING" << std::endl;
            man.move(1);
        }

        world.drawSprite(window, man);
        window.display(); // Displays the current frame
    }

    return 0;
}