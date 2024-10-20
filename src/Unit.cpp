#include "Unit.h"
#include "HeroFactory.h"
#include "Resources.h"
#include "UnitState/MoveToClosest.h"

#include <math.h>
#include "macros.h"

bool Unit::m_bool_init = HeroFactory::registerit("Heroes",
	[](const std::string& name, const sf::Vector2f& pos) -> std::unique_ptr<Unit> {
		return std::make_unique<Unit>(name, pos); });


Unit::Unit(const std::string& name,const sf::Vector2f& pos)
	:m_cost(0), m_initPos(pos), m_indexOnBoard(sf::Vector2f(-1, -1)),
	m_currentState(nullptr), m_next(Move), m_toChange(false)
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

	m_moveState = std::make_unique<MoveToClosest>(getSprite(), 100.0f);
}

Unit::Unit(const Unit& other)
	: GameObject(other),
	m_cost(other.m_cost),
	m_initPos(other.m_initPos),
	m_indexOnBoard(other.m_indexOnBoard),
	m_toChange(other.m_toChange),
	m_next(other.m_next),
	m_currentState(nullptr)
{
	//m_attackState = other.m_attackState->clone();
	m_moveState = other.m_moveState->clone(getSprite());
	m_currentState = m_moveState.get();
}

sf::Vector2i Unit::getIndex() const
{
	return m_indexOnBoard;
}

void Unit::update(const float dt)
{

	m_currentState->update(dt);

	if (m_toChange)
	{
		switchState(m_next);
	}
}

void Unit::switchState(const state s)
{
	switch (s)
	{
	case Move:
		m_currentState = m_moveState.get();
		break;
	case Attack:
		//m_currentState = m_attackState.get();
		break;
	default:
		break;
	}

	m_toChange = false;
}

void Unit::requestSwitchState(const state s)
{
	m_toChange = true;
	m_next = s;
}

void Unit::setIndex(const sf::Vector2i& point)
{
	m_indexOnBoard = point;
}

sf::Vector2i Unit::getInverseIndex() const
{
	return sf::Vector2i(std::abs((Macros::BOARD_SIZE - 1) - m_indexOnBoard.x), m_indexOnBoard.y);
}
