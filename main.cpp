#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "world.h"
#include "entity.h"

int main() {
    // Loads all textures
    TextureManager::loadTextures();

    // Creating the window
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Lithium");
    window.setVerticalSyncEnabled(true); // Framerate limiting

    // VIEW SIZE !!!
    constexpr float viewSize = 200.f;
    // Setting the viewport
    sf::View view(sf::FloatRect({-25.f, -25.f}, {viewSize,viewSize}));
    window.setView(view);

    // Camera variables
    bool isDragging = false;
    sf::Vector2i mousePressPos;
    constexpr float dragSensitivity = .25f; // Sensitivity is pretty on point at .25f (on point being the mouse and window move at the same speed)
    constexpr float minZoom = .9f;
    constexpr float maxZoom = 3.5f;

    constexpr float worldWidth = 100.f;
    constexpr float worldHeight = 100.f;

    // Creating the world and entity
    sf::Clock clock;
    World world(worldWidth,worldHeight);
    clock.stop();
    std::cout << "World creating time: " << clock.getElapsedTime().asSeconds() << "s" << std::endl;
    Entity man(50, 50, TextureManager::manTexture);

    // Game loop
    while(window.isOpen()) {
        // Handles window events
        while(const std::optional<sf::Event> event = window.pollEvent()) {
            // CLOSE requested
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }

            // RESIZE operation
            if(const auto* resized = event->getIf<sf::Event::Resized>()) {
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }

            // SCROLL movement
            if(const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>()) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePos);

                if(mouseWheelScrolled->delta > 0) {
                    view.zoom(.9f);
                } else if(mouseWheelScrolled->delta < 0) {
                    view.zoom(1.1f);
                }

                // Zoom Limits
                float currentZoom = view.getSize().x / 200.f;
                if (currentZoom < minZoom) {
                    view.setSize({viewSize / maxZoom, viewSize / maxZoom}); // Apply min zoom size
                } else if (currentZoom > maxZoom) {
                    view.setSize({viewSize / minZoom, viewSize / minZoom}); // Apply max zoom size
                }

                sf::Vector2f offset = worldMousePos - view.getCenter();
                view.setCenter(view.getCenter() + offset);
                window.setView(view);
            }

            /// CAMERA: CLICK AND DRAG ///
            // Mouse Press
            if(const auto* mousePress = event->getIf<sf::Event::MouseButtonPressed>()) {
                if(mousePress->button == sf::Mouse::Button::Left) {
                    isDragging = true;
                    mousePressPos = sf::Mouse::getPosition(window);
                }
            }

            // Mouse Release
            if(const auto* mouseRelease = event->getIf<sf::Event::MouseButtonReleased>()) {
                if(mouseRelease->button == sf::Mouse::Button::Left) {
                    isDragging = false;
                }
            }

            // Mouse Drag
            if (isDragging) {
                sf::Vector2i currentMousePos = sf::Mouse::getPosition(window);
                sf::Vector2i offset = currentMousePos - mousePressPos;


                // Reversed offset values make the window move the same direction as the mouse
                view.move({-(offset.x * dragSensitivity), -(offset.y * dragSensitivity)});

                // Clamp the camera's position to prevent it from going out of the world boundaries
                sf::Vector2f viewCenter = view.getCenter();

                // Get the minimum and maximum x and y positions the camera can move to
                float minX = 0;
                float maxX = worldWidth + 10;
                float minY = 0;
                float maxY = worldHeight + 10;

                // Apply the clamp only after the movement to prevent camera from going out of bounds
                viewCenter.x = std::clamp(viewCenter.x, minX, maxX);
                viewCenter.y = std::clamp(viewCenter.y, minY, maxY);

                view.setCenter(viewCenter);

                mousePressPos = currentMousePos;
            }

            window.setView(view);
        }

        window.clear(sf::Color(38,51,115)); // Clears previous frame and sets background to deepsea blue

        world.draw(window); // Draws world

        window.draw(man.getSprite());

        if(isKeyPressed(sf::Keyboard::Key::W)) {
            if(man.validMove(world, {0,-1})) {
                man.move(0, -1);
            }
        }
        if(isKeyPressed(sf::Keyboard::Key::A)) {
            if(man.validMove(world, {-1,0})) {
                man.move(-1, 0);
            }
        }
        if(isKeyPressed(sf::Keyboard::Key::S)) {
            if(man.validMove(world, {0,1})) {
                man.move(0, 1);
            }
        }
        if(isKeyPressed(sf::Keyboard::Key::D)) {
            if(man.validMove(world, {1,0})) {
                man.move(1, 0);
            }
        }

        window.display(); // Displays the current frame
    }

    return 0;
}