#include "world.h"

#include <iostream>

World::World(const int mapWidth, const int mapHeight)
: mapWidth(mapWidth), mapHeight(mapHeight) {
    // Loads water and land textures
    if(!waterTexture.loadFromFile(R"(..\textures\Water.png)")) {
        std::cerr << "TEXTURE ERROR : Failed to load water texture." << std::endl;
    }
    if(!landTexture.loadFromFile(R"(..\textures\Land.png)")) {
        std::cerr << "TEXTURE ERROR : Failed to load water texture." << std::endl;
    }

    // Creating the map with only water
    map.resize(mapHeight);
    for(int y = 0; y < mapHeight; y++) {
        map[y].resize(mapWidth);
        for(int x = 0; x < mapWidth; x++) {
            map[y][x] = Tile(Water, sf::Vector2i(x, y), waterTexture);
        }
    }

    // TEMPORARY LAND RECTANGLE
    for(int y = 3; y < 8; y++) {
        for(int x = 4; x < 12; x++) {
            map[y][x] = Tile(Land, sf::Vector2i(x, y), landTexture);
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