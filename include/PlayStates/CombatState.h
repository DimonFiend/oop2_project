#pragma once
#include "GameState.h"
#include "GameData.h"
#include "GameController.h"
#include "BoardUI.h"

class Player;

class CombatState : public GameState
{

public:
	CombatState(GameController& gameController, sf::RenderWindow& window, GameData& matchData,
		        Player& player1, Player& player2);
	virtual ~CombatState() = default;
	virtual void update() override;
	virtual void draw() override;
	virtual void handleInput(sf::Event event) override;

private:

	void initPlayers(Player& p, std::vector<Unit>& units);

	GameData& m_matchData;
	sf::RenderWindow& m_window;
	BoardUI& m_board;

	std::vector<Unit> m_player1;
	std::vector<Unit> m_player2;
};