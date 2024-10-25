#include "BuyingStateUnit.h"
#include "Resources.h"
#include <math.h>
#include "macros.h"

BuyingStateUnit::BuyingStateUnit(unitAttributes attributes ,const sf::Vector2f& pos)
	:m_initPos(pos),
	m_indexOnBoard(sf::Vector2f(-1, -1)),
	m_cost(attributes->getCost()),
	m_name(attributes->getName())
{
	getSprite().setTexture(Resources::Instance().getTexture(m_name));
	getSprite().setTextureRect(sf::IntRect(0, 0, 80, 80));
	auto size = getSprite().getTextureRect().getSize();
	getSprite().setOrigin(size.x / 2.f, size.y / 2.f);
	getSprite().setPosition(pos);
}

sf::Vector2i BuyingStateUnit::getIndex() const
{
	return m_indexOnBoard;
}


void BuyingStateUnit::setIndex(const sf::Vector2i& point)
{
	m_indexOnBoard = point;
}

