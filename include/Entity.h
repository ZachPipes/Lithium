#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/Sprite.hpp>

#include "World.h"

class World;
class Game;

class Entity {
    int x, y;
    sf::Sprite sprite;
    double health, hunger;

    // Counter for all stats
    // I can see this method becoming obsolete in the future with multiple entities all counting up
    // It also could lead to crazy large numbers the longer the runtime
    unsigned int ticker;

public:
    // Constructor
    Entity(int x, int y, sf::IntRect area, int health, int hunger);

    void drawEntity(sf::RenderWindow &window) const;

    void spawn();

    void kill();

    void simulate();

    /// GETTERS AND SETTERS ///
    double getHealth() const;
    double getHunger() const;

    void setHealth(double hp);
    void setHunger(double hgr);
};

#endif //ENTITY_H
