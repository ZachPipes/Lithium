#ifndef LIVING_H
#define LIVING_H

#include "entity.h"

class Living : public Entity {
    double health;
    double hunger;

public:
    // Constructor
    Living(int x, int y, const sf::Texture &texture, int hp, int hgr);

    void Sim();

    /// GETTERS AND SETTERS ///
    double getHealth() const;
    double getHunger() const;
};

#endif //LIVING_H
