#include "ArenaUnit.h"
#include "Macros.h"
#include "Resources.h"

ArenaUnit::ArenaUnit(unitAttributes attributes, const sf::Vector2f& pos, CombatState& combat)
	: m_toChange(true), m_next(Move), m_currentState(nullptr), m_leftTeam(true),
	m_name(attributes->getName()),
	m_animation(Resources::getAnimation(m_name),CharacterActions::Walk, getSprite()),
	m_hpBar(sf::Vector2f(pos.x - 26, pos.y - 44), attributes->getHealth()),
	m_attributes(attributes->getAttributes())
{
	getSprite().setTexture(Resources::Instance().getTexture(m_name));
	getSprite().setTextureRect(sf::IntRect(0, 0, 80, 80));
	auto size = getSprite().getTextureRect().getSize();
	getSprite().setOrigin(size.x / 2.f, size.y / 2.f);
	getSprite().setPosition(pos);

	m_moveState = attributes->getMoveState();

	m_moveState->setManager(combat);
	m_moveState->setUnit(*this);
}

void ArenaUnit::draw(sf::RenderWindow& window)
{
	m_hpBar.draw(window);
	GameObject::draw(window);
}

void ArenaUnit::update(const float dt)
{
	if (m_currentState) m_currentState->update(dt);

	if (m_toChange)
	{
		switchState(m_next);
	}
	m_animation.update(sf::seconds(dt));
}

void ArenaUnit::switchState(const state s)
{
	if (m_currentState) m_currentState->onExit();

	switch (s)
	{
	case Move:
		m_currentState = m_moveState.get();
		m_animation.action(CharacterActions::Walk);
		break;
	case Attack:
		//m_currentState = m_attackState.get();
		m_animation.action(CharacterActions::BaseAttack);
		break;
	default:
		m_animation.action(CharacterActions::Idle);
		break;
	}

	m_toChange = false;
	m_currentState->onEnter();
}

void ArenaUnit::requestSwitchState(const state s)
{
	m_toChange = true;
	m_next = s;
}

void ArenaUnit::flipUnit()
{
	auto scale = getSprite().getScale();
	getSprite().setScale(scale.x * (-1), 1);
}

void ArenaUnit::move(const sf::Vector2f direction)
{
	getSprite().move(direction);
	m_hpBar.move(direction);
}
