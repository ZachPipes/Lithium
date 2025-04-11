#ifndef TEXTURES_H
#define TEXTURES_H
#include <SFML/Graphics/Texture.hpp>

static sf::Texture worldAtlas;
static sf::Texture entityAtlas;

// Textures
if(worldAtlas.loadFromFile("G:/Programming/Projects/Lithium/assets/textures/worldAtlas.png")) {
    std::cerr << "Failed to load World Atlas!" << std::endl;
}
if(entityAtlas.loadFromFile("G:/Programming/Projects/Lithium/assets/textures/entityAtlas.png")) {
    std::cerr << "Failed to load Entity Atlas!" << std::endl;
}


#endif //TEXTURES_H
