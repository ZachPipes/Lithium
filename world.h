#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

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
    // Creates the base world with water textures
    World();

    // Draws the world in the window
    void draw(sf::RenderWindow& window) const;
};

#endif //WORLD_H