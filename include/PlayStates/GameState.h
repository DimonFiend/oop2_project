#pragma once
#include <SFML/Graphics.hpp>

class GameController;
class GameState {
protected: // private??
	GameController* m_game; // const?
public:
	GameState(GameController& game) : m_game(&game) {};
	virtual ~GameState() = default;

	virtual void update(const float dt) = 0;
	virtual void draw() = 0;
	virtual void handleInput(sf::Event event) = 0;
};