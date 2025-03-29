#include "entity.h"

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "world.h"

Entity::Entity(const int x, const int y, const sf::Texture& texture) : x(x), y(y), sprite(texture) {
    sprite.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)));
}

sf::Sprite Entity::getSprite() const {
    return sprite;
}

void Entity::move(const int direction) {
    // Change this in the future to be more fluid and dynamic
    sf::Sprite sprite = this->getSprite();
    switch(direction) {
        case 0: // Left
            sprite.setPosition(sf::Vector2f(static_cast<float>((x-1) * tileSize), static_cast<float>(y * tileSize)));
            x = static_cast<int>(sprite.getPosition().x);
            break;
        case 1: // Up
            sprite.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>((y+1) * tileSize)));
            break;
        case 2: // Right
            sprite.setPosition(sf::Vector2f(static_cast<float>((x+1) * tileSize), static_cast<float>(y * tileSize)));
            break;
        case 3: // Down
            sprite.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>((y-1) * tileSize)));
            break;
        default:
            std::cout << "Invalid direction chosen: \"" << direction << "\""<< std::endl;
    }
}
