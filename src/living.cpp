#include "living.h"
#include "entity.h"

// Constructor
Living::Living(const int x, const int y, const sf::Texture &texture, const int hp, const int hgr) : Entity(x, y, texture) {
    health = hp;
    hunger = hgr;
}

// SIMULATE
void Living::Sim() {

}

/// GETTERS AND SETTERS
double Living::getHealth() const { return health; }
double Living::getHunger() const { return hunger; }
