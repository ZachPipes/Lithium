#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/Sprite.hpp>

#include "world.h"

class World;

class Entity {
    std::pair<int, int> position;
    sf::Sprite sprite;

public:
    // Creates a basic entity with the man texture
    Entity(int x, int y, const sf::Texture& texture);

    // Moves the entity in the specified direction
    void move(int dx, int dy);

    // Ensures valid moves
    bool validMove(const World& world, const std::pair<int,int>& newLocation) const;

    /// Getters and Setters ///
    sf::Sprite getSprite() const;
};

#endif //ENTITY_H
