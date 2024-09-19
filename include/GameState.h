#pragma once
#include <SFML/Graphics.hpp>

class GameController;
class GameState {
private:
	const GameController* m_game;
public:
	GameState(GameController& game) : m_game(&game) {};
	virtual ~GameState() = default;

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void handleInput(sf::Event& event) = 0;
};