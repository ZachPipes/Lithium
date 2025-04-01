#ifndef WORLD_H
#define WORLD_H

#include <map>
#include <SFML/Graphics.hpp>

#include "entity.h"

constexpr int tileSize = 1;

enum tileType {Border, DeepSea, Sea, Shore, Beach, Grass, Hills, Mountains};

struct Tile {
    tileType type;
    sf::Texture texture;

    // Overloads the '<' operator so Tile can be used in maps
    bool operator<(const Tile& other) const {
        if(type != other.type) {
            return type < other.type;
        }

        return &texture < &other.texture;
    }
};

class World {
    int mapWidth, mapHeight;
    std::map<Tile, std::pair<int,int>> map;

public:
    // Creates a world with only water textures
    World(int mapWidth, int mapHeight);

    // Draws the world in the window
    void draw(sf::RenderWindow& window) const;

    // Draws a sprite in the world
    static void drawSprite(sf::RenderWindow& window, const Entity& entity);
};

#endif //WORLD_H