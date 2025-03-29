#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML/Graphics/Texture.hpp>

class TextureManager {
public:
    static sf::Texture waterTexture;
    static sf::Texture landTexture;
    static sf::Texture manTexture;

    static bool loadTextures();
};

#endif //TEXTUREMANAGER_H
