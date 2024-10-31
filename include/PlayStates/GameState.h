#pragma once
#include <SFML/Graphics.hpp>

class GameController;
class GameState {
protected:
	GameController* m_game;
public:
	GameState(GameController& game) : m_game(&game) {};
	virtual ~GameState() = default;

	virtual void update(const float dt) = 0;
	virtual void draw() = 0;
	virtual void handleInput(sf::Event event) = 0;
};