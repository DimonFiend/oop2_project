#include "Player.h"

bool Player::hasSpace() const
{
	return !m_inventory.isFull();
}

bool Player::checkContain(sf::Vector2f point)
{
	return m_inventory.checkContain(point);
}

void Player::reduceInventoryCap()
{
	m_inventory.reduceInventoryCap();
}

std::unique_ptr<BuyingStateUnit> Player::makePurchase(std::unique_ptr<BuyingStateUnit> hero)
{
	if(m_money >= hero->getCost() && hasSpace())
	{
		m_money -= hero->getCost();
		m_inventory.addHero(std::move(hero));
		return nullptr;
	}

	return std::move(hero);
}

Units& Player::getFighters()
{
	return m_inventory.getFighers();
}

