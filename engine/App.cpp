#include "App.hpp"
#include <chrono>

void App::run() {
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    constexpr double dt = 0.01;

    double currentTime = std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
    double accumulator = 0.0;

    sf::Vector2f circlePos = { 0,0 };
    double speed = 10;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        double newTime = std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
        auto frameTime = newTime - currentTime;
        currentTime = newTime;

        if (frameTime > 0.25) {
            frameTime = 0.25;
        }
        
        accumulator += frameTime;
        while (accumulator >= dt) {
            circlePos.y += speed * dt;
            shape.setPosition(circlePos);
            accumulator -= dt;
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}