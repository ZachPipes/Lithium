#include "Game.h"
#include "World.h"
#include "Entity.h"

int main() {
    Game game;

    Entity man(250,250,sf::IntRect({0,0}, {1,1}),20,20);
    Entity berryBush(270,270,sf::IntRect({1,0}, {1,1}),20,20);

    game.spawnEntity(man);
    game.spawnEntity(berryBush);
    ///////////////
    // Game loop //
    ///////////////
    while(game.running()) {
        // Update
        game.update();

        // Render
        game.render();
    }
    return 0;
}

// This code will have to be fixed later, or not implemented at all
/*
            CODE FROM ABOVE:::
            // VIEW SIZE
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
            */
