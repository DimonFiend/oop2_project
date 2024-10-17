#include "Unit.h"
#include "HeroFactory.h"
#include "Resources.h"

#include <math.h>
#include "macros.h"

bool Unit::m_bool_init = HeroFactory::registerit("Heroes",
	[](const std::string& name, const sf::Vector2f& pos) -> std::unique_ptr<Unit> {
		return std::make_unique<Unit>(name, pos); });


Unit::Unit(const std::string& name,const sf::Vector2f& pos)
	:m_cost(0), m_initPos(pos), m_indexOnBoard(sf::Vector2f(-1, -1))
{
	getSprite().setTexture(Resources::Instance().getTexture("Davis"));
	getSprite().setTextureRect(sf::IntRect(0, 0, 80, 80));
	auto size = getSprite().getTextureRect().getSize();
	getSprite().setOrigin(size.x / 2.f, size.y / 2.f);
	getSprite().setPosition(pos);

	switch (name[0])
	{
	case 'a':
		getSprite().setColor(sf::Color::Red);
		break;
	case 'b':
		getSprite().setColor(sf::Color::Green);
		break;
	case 'c':
		getSprite().setColor(sf::Color::Blue);
		break;
	}
}

sf::Vector2i Unit::getIndex() const
{
	return m_indexOnBoard;
}

void Unit::setIndex(const sf::Vector2i& point)
{
	m_indexOnBoard = point;
}

sf::Vector2i Unit::getInverseIndex() const
{
	return sf::Vector2i(std::abs((Macros::BOARD_SIZE - 1) - m_indexOnBoard.x), m_indexOnBoard.y);
}
