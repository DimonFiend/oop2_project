#include "ArenaUnit.h"
#include "Macros.h"
#include "Resources.h"

ArenaUnit::ArenaUnit(unitAttributes attributes, const sf::Vector2i& index, const sf::Vector2f& pos)
	:m_indexOnBoard(index), m_toChange(false), m_next(Move), m_currentState(nullptr),
	m_name(attributes->getName())
{

	getSprite().setTexture(Resources::Instance().getTexture(m_name));
	getSprite().setTextureRect(sf::IntRect(0, 0, 80, 80));
	auto size = getSprite().getTextureRect().getSize();
	getSprite().setOrigin(size.x / 2.f, size.y / 2.f);
	getSprite().setPosition(pos);
	//initialize with the attributes
	/*m_moveState = std::make_unique<MoveState>(*this, attributes.getSpeed());
	m_currentState = m_moveState.get();*/
}


void ArenaUnit::update(const float dt)
{

	m_currentState->update(dt);

	if (m_toChange)
	{
		switchState(m_next);
	}
}

void ArenaUnit::switchState(const state s)
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

void ArenaUnit::requestSwitchState(const state s)
{
	m_toChange = true;
	m_next = s;
}

sf::Vector2i ArenaUnit::getInverseIndex() const
{
	return sf::Vector2i(std::abs((Macros::BOARD_SIZE - 1) - m_indexOnBoard.x), m_indexOnBoard.y);
}
