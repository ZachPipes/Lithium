#include "Entity.h"

#include <SFML/Graphics/Sprite.hpp>
#include "Game.h"

Entity::Entity(const int x, const int y, const sf::IntRect area, const int health, const int hunger)
: x(x), y(y), sprite(getTexture(1), area), health(health), hunger(hunger) {
    sprite.setPosition({static_cast<float>(x), static_cast<float>(y)});
    sprite.setScale({5, 5});
    ticker = 0;
}

void Entity::drawEntity(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Entity::spawn() {

}

void Entity::kill() {

}

void Entity::simulate() {
    ticker++;
    if(ticker % 50 == 0) {
        hunger--;
    }
    if(hunger < 10 && ticker % 25 == 0) {
        health--;
    }
}

/// GETTERS AND SETTERS ///
double Entity::getHealth() const {
    return health;
}
double Entity::getHunger() const {
    return hunger;
}

void Entity::setHealth(const double hp) {
    health = hp;
}
void Entity::setHunger(const double hgr) {
    hunger = hgr;
}
