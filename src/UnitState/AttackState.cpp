#include "UnitState/AttackState.h"
#include "ArenaUnit.h"

void AttackState::update(const float dt)
{
	if (!m_target || !m_target->isAlive())
	{
		m_unit->requestSwitchState(state::Move);
		m_target = nullptr;
		return;
	}

	m_attackDelay += dt;
	if (m_attackDelay >= m_attackSpeed)
	{
		m_attackDelay -= m_attackSpeed;

		Attack();
	}
	m_animation->action(CharacterActions::Idle);
}

void AttackState::onEnter()
{
	m_attackDelay = 0;
	m_target = m_unit->getTarget();
	m_animation->action(CharacterActions::Idle);
}

void AttackState::onExit()
{
	m_target = nullptr;
	m_animation->action(CharacterActions::Idle);
}
