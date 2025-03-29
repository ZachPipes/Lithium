#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/Sprite.hpp>

class Entity {
    int x, y;
    sf::Sprite sprite;

public:
    // Creates a basic entity with the man texture
    Entity(int x, int y, const sf::Texture& texture);

    // Moves the entity in the specified direction
    void move(int direction);

    /// Getters and Setters ///
    sf::Sprite getSprite() const;
};

#endif //ENTITY_H
