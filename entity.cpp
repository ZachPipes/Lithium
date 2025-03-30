#include "entity.h"

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "world.h"

Entity::Entity(const int x, const int y, const sf::Texture& texture) : x(x * tileSize), y(y * tileSize), sprite(texture) {
    sprite.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)));
}

sf::Sprite Entity::getSprite() const {
    return sprite;
}

void Entity::move(const int direction) {
    // Change this in the future to be more fluid and dynamic
    switch(direction) {
        case 0: // Left
            if(validMove(direction)) {
                sprite.setPosition(sf::Vector2f(static_cast<float>(x-1), static_cast<float>(y)));
                x = static_cast<int>(sprite.getPosition().x);
            }
            break;
        case 1: // Up
            sprite.setPosition(sf::Vector2f(static_cast<float>(x), static_cast<float>(y-1)));
            y = static_cast<int>(sprite.getPosition().y);
            break;
        case 2: // Right
            sprite.setPosition(sf::Vector2f(static_cast<float>(x+1), static_cast<float>(y)));
            x = static_cast<int>(sprite.getPosition().x);
            break;
        case 3: // Down
            sprite.setPosition(sf::Vector2f(static_cast<float>(x), static_cast<float>(y+1)));
            y = static_cast<int>(sprite.getPosition().y);
            break;
        default:
            std::cout << "Invalid direction chosen: \"" << direction << "\""<< std::endl;
    }
}

bool Entity::validMove(const int direction) {
    return true;
}
