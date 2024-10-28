#pragma once
#include "GameData.h"
#include "BoardUI.h"
#include <SFML/Graphics.hpp>
#include "ArenaUnit.h"

class Player;
struct TextFader
{
	float m_fadeInDuration = 1.0f;   // 1 second to fade in
	float m_holdDuration = 2.0f;     // 1 second to hold full visibility
	float m_fadeOutDuration = 1.0f;  // 1 second to fade out
	float m_totalDuration = m_fadeInDuration + m_holdDuration + m_fadeOutDuration;
	float m_elapsed = 0;
	float m_alpha = 0;
};

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
	sf::Text m_onEnterText;
	TextFader m_textTimer;
	void setOnEnterText(const Player& p1, const Player& p2);
	void updateTextOpacity(float dt);
};