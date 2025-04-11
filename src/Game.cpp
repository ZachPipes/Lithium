#include "Game.h"
#include <iostream>

/// INITIALIZERS ///
void Game::initVariables() {
    // Window
    this->window = nullptr;
    this->videoMode.size = {500,500};
    this->videoMode.bitsPerPixel = 32;

    // World
    this->world = World();
    this->world.generatePerlinMap();
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(this->videoMode, "Lithium", sf::Style::None);
}

// Constructor
Game::Game() {
    this->initVariables();
    this->initWindow();
}

// Destructor
Game::~Game() {
    delete this->window;
    for(const Entity* entity : this->world.getEntities()) {
        delete entity;
    }
}

void Game::pollEvents() const {
    while(const std::optional<sf::Event> event = this->window->pollEvent()) {
        if(event->is<sf::Event::KeyPressed>()) {
            // ESCAPE //
            if(event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape) {
                this->window->close();
            }
        }
    }
}

// Runs game updates
void Game::update() const {
    this->pollEvents();
}

// Renders game objects and textures
// Steps:
//  - Clears old frame
//  - Renders game objects
//  - Displays the frame
void Game::render() const {
    this->window->clear(sf::Color(38,51,115)); // Clears previous frame and sets background to deepsea blue

    this->world.drawWorld(*this->window, worldAtlas);
    this->world.drawEntities(*this->window);

    this->window->display();
}

// Game functions
void Game::spawnEntity(const Entity& entity) const {
    this->world.addEntity(entity);
}

// Getters and Setters
bool Game::running() const {
    return this->window->isOpen();
}
sf::Texture& Game::getTexture(const int value) {
    switch(value) {
        case 0:
            return worldAtlas;
        case 1:
            return entityAtlas;
        default:
            std::cerr << "Invalid Value!" << std::endl;
    }
}