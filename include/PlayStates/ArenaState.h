#pragma once
#include "GameState.h"
#include "GameData.h"
#include "GameController.h"
#include "BoardUI.h"

class ArenaState : public GameState {
	GameData& m_matchData;
	sf::RenderWindow& m_window;
	BoardUI& m_board;
public:
	ArenaState(GameController& game, sf::RenderWindow& window, GameData& matchData);
	virtual ~ArenaState() = default;
	virtual void update() override;
	virtual void draw() override;
	virtual void handleInput(sf::Event event) override;

};