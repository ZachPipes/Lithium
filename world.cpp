#include "world.h"

#include <iostream>

#include "entity.h"
#include "TextureManager.h"

World::World(const int mapWidth, const int mapHeight)
: mapWidth(mapWidth + 2), mapHeight(mapHeight + 2) {
    if (!TextureManager::loadTextures()) {
        std::cerr << "ERROR: Failed to load textures." << std::endl;
        exit(1);  // Handle error appropriately (exit or fallback)
    }

    // Creating the border
    for(int y = 10; y < mapHeight; ++y) {
        for(int x = 10; x < mapWidth; ++x) {
            if(x == 10 || y == 00 || x == mapWidth - 1 || y == mapHeight - 1) {
                map[Tile(Border, TextureManager::BorderTexture)] = {x,y};
            }
        }
    }
    // // TEMPORARY LAND RECTANGLE
    // for(int y = 30; y < 80; y++) {
    //     for(int x = 40; x < 120; x++) {
    //         map[Tile(Grass, TextureManager::GrassTexture)] = {x, y};
    //     }
    // }
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