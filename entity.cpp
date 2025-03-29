#include "entity.h"

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

Entity::Entity(const int x, const int y, sf::Texture texture) : x(x), y(y), sprite(texture) {
    sprite.setPosition(sf::Vector2f(x, y));
}

sf::Sprite Entity::getSprite() const {
    return sprite;
}
