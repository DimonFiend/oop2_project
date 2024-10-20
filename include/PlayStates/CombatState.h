#pragma once
#include "GameData.h"
#include "BoardUI.h"
#include <SFML/Graphics.hpp>
class Player;

class CombatState {

public:
	CombatState(Player& player1, Player& player2);
	virtual ~CombatState() = default;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleInput(sf::Event event) override;

private:

	void initPlayers(Player& p, std::vector<Unit>& units);

	GameData& m_matchData;
	sf::RenderWindow& m_window;
	BoardUI& m_board;

	std::vector<Unit> m_player1;
	std::vector<Unit> m_player2;
};