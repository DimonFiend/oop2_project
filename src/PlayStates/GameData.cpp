#include "GameData.h"
#include "HumanPlayer.h"
#include <utility>
#include "Settings.h"
#include "macros.h"
#include "PlayersStatusBar.h"

GameData::GameData()
	:m_selected(nullptr), m_roundCount(0), m_playerShift(rand() % Macros::MAX_PC_PLAYERS)
{
	m_player = std::make_unique<HumanPlayer>("Player1");
	m_board = std::make_unique<BoardUI>(sf::Vector2f{ static_cast<float>(Settings::Instance().getWidth()) / 3.5f,
														(static_cast<float>(Settings::Instance().getHeight()) / 6) - 30 });;
	for(int i = 0; i < Macros::MAX_PC_PLAYERS; i++)
	{
		m_computerPlayers.push_back(std::make_unique<ComputerPlayer>("Computer " + std::to_string(i+1), *m_board));
	}
	m_statusBar = std::make_unique<PlayersStatusBar>(*this);
}

void GameData::clearLosers()
{
	m_statusBar->eraseDead();
	std::erase_if(m_computerPlayers,
		[](const std::unique_ptr<ComputerPlayer>& player) { return player->getHealth() <= 0; });
}

bool GameData::lastOpponent()
{
	if((m_player->getHealth() <= 0))
	{
		return true;
	}

	if(m_computerPlayers.size() < 1)
	{
		return true;
	}

	return false;
}
