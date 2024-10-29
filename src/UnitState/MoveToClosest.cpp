#include "UnitState/MoveToClosest.h"
#include "GameObjects/ArenaUnit.h"
#include "PlayStates/CombatState.h"

#include <iostream>
#include <cmath>

MoveToClosest::MoveToClosest(const float speed)
	: MoveState(speed), m_target(nullptr) {}

void MoveToClosest::update(const float dt)
{
	FindTarget();
	if (!m_target)
	{
		m_unit->requestSwitchState(state::Idle);
		return;
	}

	auto& pos1 = m_unit->getPosition();
	auto& pos2 = m_target->getPosition();

	sf::Vector2f vec((pos2.x - pos1.x), (pos2.y - pos1.y));
	float mag = std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
	
	if (mag <= m_unit->getAttackRange())
	{
		// Stop moving if within attack range
		m_unit->requestSwitchState(state::Attack); //attack
		return;
	}

	vec /= mag;
	vec *= dt * m_speed;
	m_unit->move(vec);
}

void MoveToClosest::onEnter()
{
	FindTarget();
}

void MoveToClosest::onExit()
{
}

void MoveToClosest::FindTarget()
{
	auto& potentialTargets = m_unit->getTeam() ? m_combatManager->getRightTeam() : m_combatManager->getLeftTeam();

	float maxDist = 999999.0f;
	int index = -1;

	for (int i = 0; i < potentialTargets.size(); i++)
	{
		float temp = calcDistance(potentialTargets[i].get());
		if (temp < maxDist)
		{
			maxDist = temp;
			index = i;
		}
	}

	if (index >= 0)
	{
		m_target = potentialTargets[index].get();
	}
	else
	{
		m_unit->requestSwitchState(state::Idle);
	}
}

float MoveToClosest::calcDistance(ArenaUnit* target)
{
	auto& pos1 = m_unit->getPosition();
	auto& pos2 = target->getPosition();

	return std::sqrt(std::pow(pos2.x - pos1.x, 2) + std::pow(pos2.y - pos1.y, 2));
}
