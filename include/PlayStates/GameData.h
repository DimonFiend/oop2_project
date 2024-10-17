#pragma once
#include <memory>
#include "HumanPlayer.h"
#include "BoardUI.h"
#include "typedefs.h"

class GameData {
public:
	GameData();
	void draw(sf::RenderWindow& window);
	Player* getPlayer() const { return m_player.get(); };
	BoardUI* getBoard() const { return m_board.get(); };
	Unit* getSelected() { return m_selected; };

private:
	std::unique_ptr<HumanPlayer> m_player;
	Unit* m_selected;
	std::unique_ptr<BoardUI> m_board;
};