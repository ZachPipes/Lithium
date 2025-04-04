#include "TextureManager.h"

#include <iostream>

sf::Texture TextureManager::BorderTexture;
sf::Texture TextureManager::DeepSeaTexture;
sf::Texture TextureManager::SeaTexture;
sf::Texture TextureManager::ShoreTexture;
sf::Texture TextureManager::BeachTexture;
sf::Texture TextureManager::GrassTexture;
sf::Texture TextureManager::HillsTexture;
sf::Texture TextureManager::MountainsTexture;
sf::Texture TextureManager::manTexture;

bool TextureManager::loadTextures() {
    // Terrain textures
    if (!BorderTexture.loadFromFile("../textures/Border.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Border texture." << std::endl;
    }
    if (!DeepSeaTexture.loadFromFile("../textures/DeepSea.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load DeepSea texture." << std::endl;
    }
    if (!SeaTexture.loadFromFile("../textures/Sea.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Sea texture." << std::endl;
    }
    if (!ShoreTexture.loadFromFile("../textures/Shore.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Shore texture." << std::endl;
    }
    if (!BeachTexture.loadFromFile("../textures/Beach.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Beach texture." << std::endl;
    }
    if (!GrassTexture.loadFromFile("../textures/Grass.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Grass texture." << std::endl;
    }
    if (!HillsTexture.loadFromFile("../textures/Hills.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Hills texture." << std::endl;
    }
    if (!MountainsTexture.loadFromFile("../textures/Mountains.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Mountains texture." << std::endl;
    }

    // Entity textures
    if (!manTexture.loadFromFile("../textures/Man.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load man texture." << std::endl;
    }
    return true;
}