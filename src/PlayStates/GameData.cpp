#include "GameData.h"
#include "HumanPlayer.h"
#include <utility>
#include "Settings.h"
#include "macros.h"
GameData::GameData()
	:m_selected(nullptr), m_roundCount(0)
{
	m_player = std::make_unique<HumanPlayer>("Hui");
	m_board = std::make_unique<BoardUI>(sf::Vector2f{ static_cast<float>(Settings::Instance().getWidth()) / 3.5f,
														(static_cast<float>(Settings::Instance().getHeight()) / 6) - 30 });;
	for(int i = 0; i < Macros::MAX_PC_PLAYERS; i++)
	{
		m_computerPlayers.push_back(std::make_unique<ComputerPlayer>("Computer " + std::to_string(i+1), *m_board));
	}
}