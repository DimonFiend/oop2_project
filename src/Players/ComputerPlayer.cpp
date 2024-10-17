#include "ComputerPlayer.h"
#include "HeroFactory.h"
ComputerPlayer::ComputerPlayer(const std::string& name, BoardUI& board)
	:Player(name), m_board(board)
{
	//for test
	int maxOnBoard = getInventory().getBoardMaxCap();
	for (int i = 0; i < maxOnBoard; i++)
	{
		int random = rand() % 3;

		getInventory().placeInBoard(std::move(HeroFactory::createHero("Heroes", {"a" + random}, board.getRandomePlacableSlot())));
	}
}

void ComputerPlayer::setShop(std::unique_ptr<Shop> shop)
{
	m_shop = std::move(shop);
}