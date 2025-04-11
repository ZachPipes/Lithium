#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "World.h"
#include "Entity.h"

class Game {
    sf::RenderWindow* window{};
    sf::VideoMode videoMode;

    sf::Texture worldAtlas;
    sf::Texture entityAtlas;

    World world;

    Entity* man;
    Entity* berryBush;

    void initVariables();
    void initWindow();


public:
    // Constructor
    Game();

    // Destructor
    virtual ~Game();

    // Window handlers
    void pollEvents() const;
    void update() const;
    void render() const;

    // Game functions
    void spawnEntity(const Entity& entity) const;

    // Getters and Setters
    bool running() const;
    sf::Texture& getTexture(int value);
};

#endif //GAME_H
