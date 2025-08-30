#include "ComputerPlayer.h"
#include "HeroFactory.h"
ComputerPlayer::ComputerPlayer(const std::string& name, BoardUI& board)
	:Player(name), m_board(board)
{
}

void ComputerPlayer::update()
{
	for (int i{ getInventory().getCurrBoardCap()}; i < getInventory().getBoardCap(); i++)
	{
		auto pos = m_board.getRandomePlacableSlot();

		if (getInventory().checkPlacableOnBoard(pos))
		{
			auto hero = HeroFactory::createBuyingPhaseHero(pos);
			if(hero->getCost() <= m_money)
			{
				getInventory().increaseCurrentCap();
				m_money -= hero->getCost();
				hero->setIndex(m_board.posToIndex(pos));
				getInventory().placeInBoard(std::move(hero));
			}
		}
	}

	if(getMoney() >= 5)
	{
		expandBoardLim();
	}
}
