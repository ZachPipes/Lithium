#include "TextureManager.h"

#include <iostream>

sf::Texture TextureManager::waterTexture;
sf::Texture TextureManager::landTexture;
sf::Texture TextureManager::manTexture;

bool TextureManager::loadTextures() {
    if (!waterTexture.loadFromFile("../textures/Water.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load water texture." << std::endl;
    }
    if (!landTexture.loadFromFile("../textures/Land.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load land texture." << std::endl;
    }
    if (!manTexture.loadFromFile("../textures/Man.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load man texture." << std::endl;
    }
    return true;
}