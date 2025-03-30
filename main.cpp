#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "world.h"

int main() {
    // Loads all textures
    TextureManager::loadTextures();

    // Creating the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Lithium");
    window.setVerticalSyncEnabled(true); // Framerate limiting

    // Creating the world and entity
    sf::Clock clock;
    World world(100,100);
    clock.stop();
    std::cout << "World creating time: " << clock.getElapsedTime().asSeconds() << "s" << std::endl;
    Entity man(7, 5, TextureManager::manTexture);

    // Game loop
    while(window.isOpen()) {
        // Handles window events
        while(const std::optional<sf::Event> event = window.pollEvent()) {
            // CLOSE requested
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color(38,51,115)); // Clears previous frame and sets background to deepsea blue

        world.draw(window); // Draws world

        window.draw(man.getSprite());
        /*
        if(isKeyPressed(sf::Keyboard::Key::W)) {
            man.move(1);
        }
        if(isKeyPressed(sf::Keyboard::Key::A)) {
            man.move(0);
        }
        if(isKeyPressed(sf::Keyboard::Key::S)) {
            man.move(3);
        }
        if(isKeyPressed(sf::Keyboard::Key::D)) {
            man.move(2);
        }*/

        window.display(); // Displays the current frame
    }

    return 0;
}