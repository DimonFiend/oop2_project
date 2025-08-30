#include "UnitState/RangedAttack.h"
#include "CombatState.h"
#include "HeroFactory.h"
#include "GameObjects/Fireball.h"

RangedAttack::RangedAttack(float attackSpeed, const std::string& obj)
	:AttackState(attackSpeed), m_obj(obj)
{}

void RangedAttack::onEnter()
{
	AttackState::onEnter();
	Attack();
}

void RangedAttack::onExit()
{
	AttackState::onExit();
}

void RangedAttack::Attack()
{
	if (m_target && m_target->isAlive())
	{
		m_combatManager->addProjectile(HeroFactory::createProjectile(m_obj,
			*m_target, m_unit->getPosition(), m_unit->getAttributes().m_attack));
		m_animation->playOnce(CharacterActions::BaseAttack);
	}
}
