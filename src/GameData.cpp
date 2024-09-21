#include "GameData.h"
#include "HumanPlayer.h"

GameData::GameData()
{
	m_player = std::make_unique<HumanPlayer>("Hui");
}

void GameData::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_player->draw(window);
}

bool GameData::checkPurchase(const Heroes* const hero)
{
	return m_player->hasSpace(); //and to check the players money
}

void GameData::makePurchase(std::unique_ptr<Heroes> hero)
{
	m_player->addHero(std::move(hero));
}

bool GameData::placeOnBoard(SlotPair* slot)
{
	return m_board.placeOnBoard(slot);
}
