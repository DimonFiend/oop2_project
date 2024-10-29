#include "UnitState/MeleeAttack.h"
#include "ArenaUnit.h"

MeleeAttack::MeleeAttack(float attackSpeed)
	:AttackState(attackSpeed)
{}

void MeleeAttack::update(const float dt)
{
	m_attackDelay += dt;
	if (m_attackDelay >= m_attackSpeed)
	{
		//m_unit->
	}
}

void MeleeAttack::onEnter()
{

}

void MeleeAttack::onExit()
{

}

void MeleeAttack::Attack()
{

}
