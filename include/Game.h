#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

class Game {
    sf::RenderWindow* window;
    sf::VideoMode videoMode;

    void initVariables();
    void initWindow();

public:
    // Constructor
    Game();

    // Destructor
    virtual ~Game();

    void pollEvents() const;

    void update() const;

    void render() const;

    // Getters and Setters
    bool running() const;
};

#endif //GAME_H
