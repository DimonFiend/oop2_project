#include "UnitsAttributes.h"
#include <stdexcept>

void UnitsAttributes::setAttack(unsigned int attack)
{
	if (attack <= 0)
	{
		throw std::invalid_argument("Unit Attack must be a positive number");
	}

	m_attributes.m_attack = attack;
}

void UnitsAttributes::setHealth(unsigned int health)
{
	if (health <= 0)
	{
		throw std::invalid_argument("Unit Health must be a positive number");
	}
	m_attributes.m_health = health;
}

void UnitsAttributes::setSpeed(unsigned int speed)
{
	m_attributes.m_speed = speed;
}

void UnitsAttributes::setCost(unsigned int cost)
{
	if (cost > 15 || cost == 0)
	{
		throw std::invalid_argument("Unit Cost must be between 1-15");
	}

	m_attributes.m_cost = cost;
}

void UnitsAttributes::setAttackRange(unsigned int attackRange)
{
	if (attackRange <= 0)
	{
		throw std::invalid_argument("Unit Attack Range must be a positive number");
	}
	m_attributes.m_attackRange = attackRange;
}

void UnitsAttributes::setName(const std::string& name)
{
	if (name.empty())
	{
		throw std::invalid_argument("Unit must be provided with name");
	}

	m_name = name;
}

const unsigned int UnitsAttributes::getAttack() const
{
	return m_attributes.m_attack;
}

const unsigned int UnitsAttributes::getHealth() const
{
	return m_attributes.m_health;
}

const unsigned int UnitsAttributes::getSpeed() const
{
	return m_attributes.m_speed;
}

const unsigned int UnitsAttributes::getCost() const
{
	return m_attributes.m_cost;
}

const unsigned int UnitsAttributes::getAttackRange() const
{
	return m_attributes.m_attackRange;
}

const std::string UnitsAttributes::getName() const
{
	return m_name;
}

std::unique_ptr<MoveState> UnitsAttributes::getMoveState()
{
	return std::move(m_moveState);
}


