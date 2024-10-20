#pragma once
#include "GameState.h"
#include "GameData.h"
#include "GameController.h"
#include "BoardUI.h"
#include "CombatState.h"

class ArenaState : public GameState {
	std::vector<std::unique_ptr<CombatState> m_combats;

	sf::RenderWindow& m_window;
	BoardUI& m_board;

	void setPlayersCombat(GameData& matchData);
public:
	ArenaState(GameController& game, sf::RenderWindow& window, GameData& matchData);
	virtual ~ArenaState() = default;
	virtual void update() override;
	virtual void draw() override;
	virtual void handleInput(sf::Event event) override;

};