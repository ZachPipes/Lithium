#include <iostream>

#include "world.h"
#include "TextureManager.h"
#include "PerlinNoise.hpp"

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

    // Generating the world
    const siv::PerlinNoise::seed_type seed = 121569189489843456u;
    const siv::PerlinNoise perlin { seed };

    // Values for scale calculation
    constexpr int minVal = 1;
    constexpr int maxVal = 7;

    for(int y = 0; y < 100; y++) {
        for(int x = 0; x < 100; x++) {
            const double noise = perlin.octave2D_01((x * 0.01), (y * 0.01), 6,.5);

            const int scaled_noise = minVal + (maxVal - minVal) * noise;

            // weighed_noise to tiles
            switch(scaled_noise) {
                case 1:
                    map[{x,y}] = Tile(DeepSea, TextureManager::SeaTexture);
                    break;
                case 2:
                    map[{x,y}] = Tile(Sea, TextureManager::SeaTexture);
                    break;
                case 3:
                    map[{x,y}] = Tile(Shore, TextureManager::ShoreTexture);
                    break;
                case 4:
                    map[{x,y}] = Tile(Beach, TextureManager::BeachTexture);
                    break;
                case 5:
                    map[{x,y}] = Tile(Grass, TextureManager::GrassTexture);
                    break;
                case 6:
                    map[{x,y}] = Tile(Hills, TextureManager::HillsTexture);
                    break;
                case 7:
                    map[{x,y}] = Tile(Mountains, TextureManager::MountainsTexture);
                    break;
                default:
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
