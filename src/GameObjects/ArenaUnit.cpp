#include "ArenaUnit.h"
#include "Macros.h"
#include "Resources.h"

ArenaUnit::ArenaUnit(unitAttributes attributes, const sf::Vector2f& pos, CombatState& combat)
	: m_toChange(true), m_next(Move), m_currentState(nullptr), m_leftTeam(true),
	m_name(attributes->getName()),
	m_animation(Resources::getAnimation(m_name),CharacterActions::Walk, getSprite()),
	m_hpBar(sf::Vector2f(pos.x - 26, pos.y - 44), attributes->getHealth()),
	m_attributes(attributes->getAttributes()),
	m_target(nullptr)
{
	getSprite().setTexture(Resources::Instance().getTexture(m_name));
	getSprite().setTextureRect(sf::IntRect(0, 0, 80, 80));
	auto size = getSprite().getTextureRect().getSize();
	getSprite().setOrigin(size.x / 2.f, size.y / 2.f);
	getSprite().setPosition(pos);

	m_moveState = attributes->getMoveState();
	m_attackState = attributes->getAttackState();

	m_moveState->setManager(combat);
	m_attackState->setManager(combat);

	m_moveState->setUnit(*this);
	m_attackState->setUnit(*this);
	
	m_moveState->setAnimation(m_animation);
	m_attackState->setAnimation(m_animation);
}

void ArenaUnit::draw(sf::RenderWindow& window)
{
	if(this->isAlive()) m_hpBar.draw(window);

	GameObject::draw(window);
}

void ArenaUnit::update(const float dt)
{
	m_animation.update(sf::seconds(dt));

	if (m_currentState) m_currentState->update(dt);

	if (m_toChange)
	{
		switchState(m_next);
	}
}

void ArenaUnit::switchState(const state s)
{
	if (m_currentState) m_currentState->onExit();

	switch (s)
	{
	case Move:
		m_currentState = m_moveState.get();
		break;
	case Attack:
		m_currentState = m_attackState.get();
		break;
	case Death:
		m_currentState = nullptr;
		m_animation.playOnce(CharacterActions::Death);
		break;
	default:
		m_currentState = nullptr;
		m_animation.action(CharacterActions::Idle);
		break;
	}

	m_toChange = false;

	if(m_currentState) m_currentState->onEnter();
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

void ArenaUnit::changeHP(const int hp)
{
	m_hpBar.changeHP(hp);
	if(!isAlive()) requestSwitchState(state::Death);
}

void ArenaUnit::move(const sf::Vector2f direction)
{
	getSprite().move(direction);
	m_hpBar.move(direction);
}
