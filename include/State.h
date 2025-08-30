#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class GameEngine;
class State {
public:
	State(GameEngine& engine);
	virtual ~State() = default;
	virtual void update(const float dt) = 0;
	virtual void draw() = 0;
	virtual void handleInput(sf::Event event) = 0;
	virtual void nextState(std::unique_ptr<State> state, bool change);
	virtual void changeState() = 0;
	GameEngine& getEngine() { return m_engine; };
public:
	GameEngine& m_engine;
};