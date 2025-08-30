#pragma once
#include "GameData.h"
#include "BoardUI.h"
#include <SFML/Graphics.hpp>
#include "ArenaUnit.h"
#include "Player.h"
#include "Projectile.h"

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
	bool isFinished() const { return m_finished; }
	void addProjectile(std::unique_ptr<Projectile> projectile);
private:
	float sort_timer = 0;
	float sort_interval = 2.f;
	bool m_finished = false;
	BoardUI& m_board;
	Player& m_player1;
	Player& m_player2;
	arenaUnits m_player1Units;
	arenaUnits m_player2Units;
	sf::Text m_onEnterText;
	TextFader m_textTimer;
	std::vector<std::unique_ptr<Projectile>> m_projectiles;

	void initPlayerOne(arenaUnits& units);
	void initPlayerTwo(arenaUnits& units);
	
	void processProjectiles(const float dt);
	void setOnEnterText();
	void updateTextOpacity(float dt);
	void sortForDrawing();
	void checkForWinner();
	bool unitIsAlive(const arenaUnits& units);
	int unitCount(const arenaUnits& units);

	struct CompareByDistance {
		bool operator()(const std::unique_ptr<ArenaUnit>& a, const std::unique_ptr<ArenaUnit>& b) const
		{
			return a->getPosition().y < b->getPosition().y;
		}
	};
};