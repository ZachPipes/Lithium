#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>

class Entity;

enum Tile {DeepSea, Sea, Shore, Beach, Grass, Hills, Mountains};

class World {
    static constexpr int WIDTH = 100;
    static constexpr int HEIGHT = 100;
    std::vector<std::vector<int>> perlinMap;
    std::vector<Entity>* entities;

public:
    World();

    void generatePerlinMap();

    void drawWorld(sf::RenderWindow& window, const sf::Texture& atlas) const;

    void drawEntities(sf::RenderWindow& window) const;

    /// GETTERS AND SETTERS ///
    [[nodiscard]] std::vector<Entity>* getEntities() const;
    void addEntity(const Entity& entity) const;
};

#endif //WORLD_H
