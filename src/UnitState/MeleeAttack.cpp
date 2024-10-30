#include "UnitState/MeleeAttack.h"
#include "ArenaUnit.h"
#include "CombatState.h"

MeleeAttack::MeleeAttack(float attackSpeed)
	:AttackState(attackSpeed)
{}

void MeleeAttack::update(const float dt)
{
	if(!m_target || !m_target->isAlive())
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

void MeleeAttack::onEnter()
{
	m_attackDelay = 0;
	m_target = m_unit->getTarget();
	Attack();
	m_animation->action(CharacterActions::Idle);
}

void MeleeAttack::onExit()
{
	
}

void MeleeAttack::Attack()
{
	if (m_target && m_target->isAlive())
	{
		m_animation->playOnce(CharacterActions::BaseAttack);
		m_target->changeHP(-m_unit->getAttributes().m_attack);
	}
}
