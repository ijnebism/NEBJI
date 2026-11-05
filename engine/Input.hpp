#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>

using Action = int;

class Input {
public:
	void bind(Action action, sf::Keyboard::Key key);
	void update();
	bool isHeld(Action action) const;

private:
	std::unordered_map<Action, sf::Keyboard::Key> bindings;
	std::unordered_map<Action, bool> held;
};