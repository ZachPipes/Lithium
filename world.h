#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include "entity.h"

enum tileType {Land, Water};

struct Tile {
    tileType type;
    sf::Vector2i pos;
    sf::Texture texture;
};

class World {
    const int tileSize = 40;
    int mapWidth, mapHeight;
    std::vector<std::vector<Tile>> map;

public:
    // Creates a world with only water textures
    World(int mapWidth, int mapHeight);

    // Draws the world in the window
    void draw(sf::RenderWindow& window) const;

    // Draws a sprite in the world
    static void drawSprite(sf::RenderWindow& window, const Entity& entity);
};

#endif //WORLD_H