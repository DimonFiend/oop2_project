#include "BuyingStateUnit.h"
#include "Resources.h"
#include <math.h>
#include "macros.h"
#include "CharacterActions.h"
BuyingStateUnit::BuyingStateUnit(unitAttributes attributes ,const sf::Vector2f& pos)
	:m_initPos(pos),
	m_indexOnBoard(sf::Vector2f(-1, -1)),
	m_cost(attributes->getCost()),
	m_name(attributes->getName()),
	m_animation(Resources::getAnimation(m_name), CharacterActions::Idle, getSprite())
{
	getSprite().setTexture(Resources::Instance().getTexture(m_name));
	getSprite().setTextureRect(sf::IntRect(0, 0, 80, 80));
	auto size = getSprite().getTextureRect().getSize();
	getSprite().setOrigin(size.x / 2.f, size.y / 2.f);
	getSprite().setPosition(pos);
}

void BuyingStateUnit::update(const float dtTime)
{
	m_animation.update(sf::seconds(dtTime));
}

sf::Vector2i BuyingStateUnit::getIndex() const
{
	return m_indexOnBoard;
}


void BuyingStateUnit::setIndex(const sf::Vector2i& point)
{
	m_indexOnBoard = point;
}

sf::Vector2i BuyingStateUnit::getInverseIndex() const
{
	return sf::Vector2i(std::abs((Macros::BOARD_SIZE - 1) - m_indexOnBoard.x), m_indexOnBoard.y);
}

