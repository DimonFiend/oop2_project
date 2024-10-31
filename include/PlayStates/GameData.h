#pragma once
#include <memory>
#include "HumanPlayer.h"
#include "BoardUI.h"
#include "typedefs.h"
#include "ComputerPlayer.h"

class PlayersStatusBar;
class GameData {
public:
	GameData();
	Player* getPlayer() const { return m_player.get(); };
	BoardUI* getBoard() const { return m_board.get(); };
	BuyingStateUnit* getSelected() { return m_selected; };
	ComputerVector& getComputerPlayers() { return m_computerPlayers; };
	const int getRoundCount() const {return m_roundCount;};
	int nextRound() { return ++m_roundCount; };
	const int getShift() const { return m_playerShift; };
	PlayersStatusBar* getStatusBar() { return m_statusBar.get(); };
	void clearLosers();
	bool lastOpponent();
private:
	std::unique_ptr<HumanPlayer> m_player;
	ComputerVector m_computerPlayers;
	BuyingStateUnit* m_selected;
	std::unique_ptr<PlayersStatusBar> m_statusBar;
	std::unique_ptr<BoardUI> m_board;
	int m_roundCount;
	int m_playerShift;
};