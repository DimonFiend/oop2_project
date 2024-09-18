#include "Player.h"

void Player::addHero(std::unique_ptr<Heroes> hero)
{
		m_inventory.addHero(std::move(hero));
}