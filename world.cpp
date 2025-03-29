#include "world.h"

#include <iostream>

World::World() {
    mapWidth = 20;
    mapHeight = 15;

    // TEMPORARY WATER TILE
    sf::Texture texture;
    if(!texture.loadFromFile(R"(..\textures\Water.png)")) {
        std::cerr << "TEXTURE ERROR : Failed to load water texture." << std::endl;
    }

    map.resize(mapHeight);
    for(int y = 0; y < mapHeight; y++) {
        map[y].resize(mapWidth);
        for(int x = 0; x < mapWidth; x++) {
            map[y][x] = Tile(Water, sf::Vector2i(x, y), texture);
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