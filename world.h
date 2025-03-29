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
    int mapWidth, mapHeight;
    std::vector<std::vector<Tile>> map;

    sf::Texture waterTexture;
    sf::Texture landTexture;

public:
    // Creates a world with only water textures
    World(int mapWidth, int mapHeight);

    // Draws the world in the window
    void draw(sf::RenderWindow& window) const;
};

#endif //WORLD_H