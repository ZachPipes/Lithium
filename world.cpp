#include "world.h"

#include <iostream>

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
            if(x == 10 || y == 10 || x == mapWidth - 1 || y == mapHeight - 1) {
                map[{x,y}] = Tile(Border, TextureManager::BorderTexture);
            }
        }
    }
}

void World::draw(sf::RenderWindow& window) const {
    for(const auto& cell : map) {
        sf::Sprite sprite(cell.second.texture);
        sprite.setPosition({static_cast<float>(cell.first.first), static_cast<float>(cell.first.second)});
        window.draw(sprite);
    }
}

void World::drawSprite(sf::RenderWindow& window, const Entity& entity) {
    window.draw(entity.getSprite());
}

/// Getters and Setters ///
tileType World::getTileType(const std::pair<int,int> location) const {
    auto it = map.find(location);
    if(it != map.end()) {
        return it->second.type;
    }
    return DeepSea;
}
