#include "Game.h"

/// INITIALIZERS ///
void Game::initVariables() {
    this->window = nullptr;
    this->videoMode.size = {600,600};
    this->videoMode.bitsPerPixel = 32;
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

// Renders game objects
// Steps:
//  - Clears old frame
//  - Renders game objects
//  - Displays the frame
void Game::render() const {
    this->window->clear(sf::Color(38,51,115)); // Clears previous frame and sets background to deepsea blue

    this->window->display();
}

// Getters and Setters
bool Game::running() const {
    return this->window->isOpen();
}
