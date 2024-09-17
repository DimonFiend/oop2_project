#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "HumanPlayer.h"

class GameController;
class GameLevel : public GameState {
private:
	Board m_board;
	std::unique_ptr<HumanPlayer> m_player;
public:
	GameLevel(GameController& controller) : GameState(controller) { m_player = std::make_unique<HumanPlayer>("Gay"); };
	virtual ~GameLevel() = default;
	void draw(sf::RenderWindow& window);
	void update();
	void processEvents(sf::RenderWindow& window);
};