#include "entity.h"

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include "world.h"

Entity::Entity(const int x, const int y, const sf::Texture &texture) : sprite(texture) {
    position.first = x * tileSize;
    position.second = y * tileSize;
    sprite.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)));
}

sf::Sprite Entity::getSprite() const {
    return sprite;
}

void Entity::move(const int dx, const int dy) {
    // Change this in the future to be more fluid and dynamic
    sprite.setPosition(sf::Vector2f(static_cast<float>(position.first+dx), static_cast<float>(position.second+dy)));
    position.first += dx;
    position.second += dy;
}

bool Entity::validMove(const World &world, const std::pair<int, int> &newLocation) const {
    tileType target = world.getTileType({position.first + newLocation.first, position.second + newLocation.second});
    if(target == Border) {
        return false;
    }
    return true;
}
