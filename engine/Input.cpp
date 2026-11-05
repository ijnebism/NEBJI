#include "Input.hpp"

void Input::bind(Action action, sf::Keyboard::Key key) {
    bindings[action] = key;
    held[action] = false;
}

void Input::update() {
    for (const auto& [action, key] : bindings) {
        held[action] = sf::Keyboard::isKeyPressed(key);
    }
}

bool Input::isHeld(Action action) const {
    auto it = held.find(action);
    return it != held.end() && it->second;
}