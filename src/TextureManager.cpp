#include "TextureManager.h"

#include <iostream>

std::string TextureManager::textureDirectory = "G:/Programming/Projects/Lithium/assets/textures";

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
    if (!BorderTexture.loadFromFile(textureDirectory + "/Border.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Border texture." << std::endl;
    }
    if (!DeepSeaTexture.loadFromFile(textureDirectory + "/DeepSea.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load DeepSea texture." << std::endl;
    }
    if (!SeaTexture.loadFromFile(textureDirectory + "/Sea.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Sea texture." << std::endl;
    }
    if (!ShoreTexture.loadFromFile(textureDirectory + "/Shore.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Shore texture." << std::endl;
    }
    if (!BeachTexture.loadFromFile(textureDirectory + "/Beach.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Beach texture." << std::endl;
    }
    if (!GrassTexture.loadFromFile(textureDirectory + "/Grass.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Grass texture." << std::endl;
    }
    if (!HillsTexture.loadFromFile(textureDirectory + "/Hills.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Hills texture." << std::endl;
    }
    if (!MountainsTexture.loadFromFile(textureDirectory + "/Mountains.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load Mountains texture." << std::endl;
    }

    // Entity textures
    if (!manTexture.loadFromFile(textureDirectory + "/Man.png")) {
        std::cerr << "TEXTURE ERROR: Failed to load man texture." << std::endl;
    }
    return true;
}
