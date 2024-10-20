#pragma once
#include "GameData.h"
#include "BoardUI.h"
#include <SFML/Graphics.hpp>
class Player;

class CombatState {

public:
	CombatState(Player& player1, Player& player2, BoardUI& board);
	~CombatState() = default;
	void update();
	void draw(sf::RenderWindow& window);
	void handleInput(sf::Event event);

private:

	void initPlayers(Player& p, std::vector<Unit>& units);
	BoardUI& m_board;
	std::vector<Unit> m_player1;
	std::vector<Unit> m_player2;
};