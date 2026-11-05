#include "App.hpp"
#include "Input.hpp"
#include <chrono>

enum GameAction {MoveLeft, MoveRight};

void App::run() {
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    constexpr double dt = 0.01;

    double currentTime = std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
    double accumulator = 0.0;

    sf::Vector2f circlePos = { 0,0 };
    double speed = 100;

    Input input;
    input.bind(MoveLeft, sf::Keyboard::Key::A);
    input.bind(MoveRight, sf::Keyboard::Key::D);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        input.update();

        double newTime = std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
        auto frameTime = newTime - currentTime;
        currentTime = newTime;

        if (frameTime > 0.25) {
            frameTime = 0.25;
        }
        
        accumulator += frameTime;
        while (accumulator >= dt) {
            if (input.isHeld(MoveLeft)) {
                circlePos.x -= speed * dt;
            }
            if (input.isHeld(MoveRight)) {
                circlePos.x += speed * dt;
            }
            accumulator -= dt;
        }

        shape.setPosition(circlePos);
        window.clear();
        window.draw(shape);
        window.display();
    }
}