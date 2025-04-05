#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML/Graphics/Texture.hpp>

class TextureManager {
public:
    static std::string textureDirectory;

    static sf::Texture BorderTexture;
    static sf::Texture DeepSeaTexture;
    static sf::Texture SeaTexture;
    static sf::Texture ShoreTexture;
    static sf::Texture BeachTexture;
    static sf::Texture GrassTexture;
    static sf::Texture HillsTexture;
    static sf::Texture MountainsTexture;
    static sf::Texture manTexture;

    static bool loadTextures();
};

#endif //TEXTUREMANAGER_H
