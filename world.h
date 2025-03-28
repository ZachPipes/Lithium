#ifndef WORLD_H
#define WORLD_H
#include <iostream>

enum tileType {Land, Water};

struct Tile {
    tileType type;
    sf::Vector2i pos;
    sf::Texture texture;
};

class World {
    const int tileSize = 40;
    int mapWidth;
    int mapHeight;
    std::vector<std::vector<Tile>> map;

public:
    World() {
        mapWidth = 20;
        mapHeight = 15;
        map.resize(mapHeight);

        // TEMPORARY WATER TILE
        sf::Texture texture;
        if(!texture.loadFromFile(R"(G:\Programming\Projects\Lithium\textures\Water.png)")) {
            std::cerr << "TEXTURE ERROR : Failed to load water texture." << std::endl;
        }

        for(int y = 0; y < mapHeight; y++) {
            map[y].resize(mapWidth);
            for(int x = 0; x < mapWidth; x++) {
                map[y][x] = Tile(Water, sf::Vector2i(x, y), texture);
            }
        }
    }

    void draw(sf::RenderWindow& window) const {
        for(int height = 0; height < mapHeight; height++) {
            for(int width = 0; width < mapWidth; width++) {
                sf::Sprite sprite(map[height][width].texture);
                sprite.setPosition(sf::Vector2f(static_cast<float>(width * tileSize), static_cast<float>(height * tileSize)));

                window.draw(sprite);
            }
        }
    }
};

#endif //WORLD_H
