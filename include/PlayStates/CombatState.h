#pragma once
#include "GameData.h"
#include "BoardUI.h"
#include <SFML/Graphics.hpp>
#include "ArenaUnit.h"

class Player;

typedef std::vector<std::unique_ptr<ArenaUnit>> arenaUnits;

class CombatState {

public:
	CombatState(Player& player1, Player& player2, BoardUI& board);
	~CombatState() = default;

	void update(const float dt = 1);
	void draw(sf::RenderWindow& window);
	void handleInput(sf::Event event);

	arenaUnits& getLeftTeam();
	arenaUnits& getRightTeam();


private:

	void initPlayerOne(Player& p, arenaUnits& units);
	void initPlayerTwo(Player& p, arenaUnits& units);
	BoardUI& m_board;
	arenaUnits m_player1;
	arenaUnits m_player2;
};