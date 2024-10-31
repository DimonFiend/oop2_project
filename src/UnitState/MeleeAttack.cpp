#include "UnitState/MeleeAttack.h"
#include "ArenaUnit.h"
#include "CombatState.h"

MeleeAttack::MeleeAttack(float attackSpeed)
	:AttackState(attackSpeed)
{}

void MeleeAttack::onEnter()
{
	AttackState::onEnter();
	Attack();
}

void MeleeAttack::onExit()
{
	AttackState::onExit();
}

void MeleeAttack::Attack()
{
	if (m_target && m_target->isAlive())
	{
		m_animation->playOnce(CharacterActions::BaseAttack);
		m_target->changeHP(-m_unit->getAttributes().m_attack);
	}
}
