#pragma once
#include <memory>
#include "HumanPlayer.h"
#include "BoardUI.h"
#include "typedefs.h"
#include "ComputerPlayer.h"

class GameData {
public:
	GameData();
	Player* getPlayer() const { return m_player.get(); };
	BoardUI* getBoard() const { return m_board.get(); };
	Unit* getSelected() { return m_selected; };
	ComputerVector& getComputerPlayers() { return m_computerPlayers; };

private:
	std::unique_ptr<HumanPlayer> m_player;
	ComputerVector m_computerPlayers;
	Unit* m_selected;
	std::unique_ptr<BoardUI> m_board;
};