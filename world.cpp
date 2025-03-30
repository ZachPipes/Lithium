#include "world.h"

#include <iostream>

#include "entity.h"
#include "TextureManager.h"

World::World(const int mapWidth, const int mapHeight)
: mapWidth(mapWidth), mapHeight(mapHeight) {
    if (!TextureManager::loadTextures()) {
        std::cerr << "ERROR: Failed to load textures." << std::endl;
        exit(1);  // Handle error appropriately (exit or fallback)
    }

    // Creating the map with only water
    /*for(int y = 0; y < mapHeight; y++) {
        for(int x = 0; x < mapWidth; x++) {
            map[Tile(DeepSea, TextureManager::DeepSeaTexture)] = {x, y};
        }
    }*/

    // TEMPORARY LAND RECTANGLE
    for(int y = 3; y < 8; y++) {
        for(int x = 4; x < 12; x++) {
            map[Tile(Grass, TextureManager::GrassTexture)] = {x, y};
        }
    }
}

void World::draw(sf::RenderWindow& window) const {
    for(const auto& cell : map) {
        sf::Sprite sprite(cell.first.texture);
        sprite.setPosition({static_cast<float>(cell.second.first), static_cast<float>(cell.second.second)});
        window.draw(sprite);
    }
}

void World::drawSprite(sf::RenderWindow& window, const Entity& entity) {
    window.draw(entity.getSprite());
}