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
    map.resize(mapHeight);
    for(int y = 0; y < mapHeight; y++) {
        map[y].resize(mapWidth);
        for(int x = 0; x < mapWidth; x++) {
            map[y][x] = Tile(Water, sf::Vector2i(x, y), TextureManager::waterTexture);
        }
    }

    // TEMPORARY LAND RECTANGLE
    for(int y = 3; y < 8; y++) {
        for(int x = 4; x < 12; x++) {
            map[y][x] = Tile(Land, sf::Vector2i(x, y), TextureManager::landTexture);
        }
    }
}

void World::draw(sf::RenderWindow& window) const {
    for(int height = 0; height < mapHeight; height++) {
        for(int width = 0; width < mapWidth; width++) {
            sf::Sprite sprite(map[height][width].texture);
            sprite.setPosition(sf::Vector2f(static_cast<float>(width * tileSize), static_cast<float>(height * tileSize)));

            window.draw(sprite);
        }
    }
}

void World::drawSprite(sf::RenderWindow& window, Entity& entity) {
    window.draw(entity.getSprite());
}