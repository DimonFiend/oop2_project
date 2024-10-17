#include "GameData.h"
#include "HumanPlayer.h"
#include <utility>
#include "Settings.h"

GameData::GameData()
	:m_selected(nullptr)
{
	m_player = std::make_unique<HumanPlayer>("Hui");
	m_board = std::make_unique<BoardUI>(sf::Vector2f{ static_cast<float>(Settings::Instance().getWidth()) / 3.5f,
														(static_cast<float>(Settings::Instance().getHeight()) / 6) - 30 });;
}

void GameData::draw(sf::RenderWindow& window)
{
	m_board->draw(window);
	m_player->draw(window);
}
