#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"

#include <memory>
#include <queue>
#include <stack>

class GameEngine {
public:
	GameEngine();
	void run();
	void setState(std::unique_ptr<State> state, bool change);

private:
	void update(const float dt);
	void render();
	void handleInput();
	void changeState();
	sf::RenderWindow m_window;
	std::queue<std::pair<std::unique_ptr<State>, bool>> m_states_q;
	std::stack<std::unique_ptr<State>> m_states;
};
