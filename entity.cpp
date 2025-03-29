#include "entity.h"

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

Entity::Entity(const int x, const int y, const sf::Texture& texture) : x(x), y(y), sprite(texture) {
    sprite.setPosition(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

sf::Sprite Entity::getSprite() const {
    return sprite;
}
