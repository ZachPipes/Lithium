#include "World.h"
#include "Entity.h"

#include <iostream>

#include "PerlinNoise.hpp"

World::World() {
    perlinMap.resize(100);
}

void World::generatePerlinMap() {
    constexpr auto seed = static_cast<siv::PerlinNoise::seed_type>(14159265358979323);
    const siv::PerlinNoise perlin { seed };

    for(int y = 0; y < 100; y++) {
        for(int x = 0; x < 100; x++) {
            // Based off the # of variables in the Tile enum
            constexpr int maxVal = 7;
            constexpr int minVal = 1;

            const double noise = perlin.octave2D_01(x * 0.01,y * 0.01,6,.5);
            const int scaled_noise = minVal + (maxVal - minVal) * noise;
            perlinMap[y].push_back(scaled_noise);
        }
    }
}

void World::drawWorld(sf::RenderWindow& window, const sf::Texture& atlas) const {
    for(float y = 0; y < 100; y++) {
        for(float x = 0; x < 100; x++) {
            const int tile = perlinMap[y][x];
            sf::Sprite sprite(atlas, sf::IntRect(sf::Vector2(0,0),sf::Vector2(1,1)));
            sprite.setPosition({x*5,y*5});
            // This is not the way I want to do this, but it will have to wait till later
            sprite.setScale(sf::Vector2f(5,5));

            switch(tile) {
                case 1:
                    sprite.setTextureRect(sf::IntRect(sf::Vector2(1,0),sf::Vector2(1,1)));
                    break;
                case 2:
                    sprite.setTextureRect(sf::IntRect(sf::Vector2(2,0),sf::Vector2(1,1)));
                    break;

                case 3:
                    sprite.setTextureRect(sf::IntRect(sf::Vector2(3,0),sf::Vector2(1,1)));
                    break;

                case 4:
                    sprite.setTextureRect(sf::IntRect(sf::Vector2(4,0),sf::Vector2(1,1)));
                    break;

                case 5:
                    sprite.setTextureRect(sf::IntRect(sf::Vector2(5,0),sf::Vector2(1,1)));
                    break;

                case 6:
                    sprite.setTextureRect(sf::IntRect(sf::Vector2(6,0),sf::Vector2(1,1)));
                    break;

                case 7:
                    sprite.setTextureRect(sf::IntRect(sf::Vector2(7,0),sf::Vector2(1,1)));
                    break;

                default:
                    sprite.setTextureRect(sf::IntRect(sf::Vector2(0,0),sf::Vector2(1,1)));
                    std::cout << "BAD TILE" << std::endl;
                    break;
            }

            window.draw(sprite);
        }
    }
}

void World::drawEntities(sf::RenderWindow &window) const {
    for(auto & entity : *entities) {
        entity.drawEntity(window);
    }
}

/// Getters and Setters ///
std::vector<Entity>* World::getEntities() const {
    return entities;
}
void World::addEntity(const Entity& entity) const {
    entities->push_back(entity);
}
