#include "ComputerPlayer.h"
#include "HeroFactory.h"
ComputerPlayer::ComputerPlayer(const std::string& name, BoardUI& board)
	:Player(name), m_board(board)
{
	srand(time(0));
	//for test
	int maxOnBoard = getInventory().getBoardMaxCap();
	for (int i = 0; i < maxOnBoard; i++)
	{
		int random = rand() % 2;

		getInventory().placeInBoard(HeroFactory::createBuyingPhaseHero("Davis", board.getRandomePlacableSlot()));
		auto pos = getInventory().getFighers()[i]->getPosition();
		getInventory().getFighers()[i]->setIndex(board.posToIndex(pos));
	}
}

void ComputerPlayer::setShop(std::unique_ptr<Shop> shop)
{
	m_shop = std::move(shop);
}