#include "UnitsAttributes.h"
#include <stdexcept>

void UnitsAttributes::setAttack(unsigned int attack)
{
	if (attack <= 0)
	{
		throw std::invalid_argument("Unit Attack must be a positive number");
	}

	m_attack = attack;
}

void UnitsAttributes::setHealth(unsigned int health)
{
	if (health <= 0)
	{
		throw std::invalid_argument("Unit Health must be a positive number");
	}
	m_health = health;
}

void UnitsAttributes::setSpeed(unsigned int speed)
{
	if (speed < 0)
	{
		throw std::invalid_argument("Unit Speed must be a positive number");
	}

	m_speed = speed;
}

void UnitsAttributes::setCost(unsigned int cost)
{
	if (cost < 0)
	{
		throw std::invalid_argument("Unit Cost must be a positive number");
	}

	m_cost = cost;
}

void UnitsAttributes::setAttackRange(unsigned int attackRange)
{
	if (attackRange <= 0)
	{
		throw std::invalid_argument("Unit Attack Range must be a positive number");
	}
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
	return m_attack;
}

const unsigned int UnitsAttributes::getHealth() const
{
	return m_health;
}

const unsigned int UnitsAttributes::getSpeed() const
{
	return m_speed;
}

const unsigned int UnitsAttributes::getCost() const
{
	return m_cost;
}

const unsigned int UnitsAttributes::getAttackRange() const
{
	return m_attackRange;
}

const std::string UnitsAttributes::getName() const
{
	return m_name;
}

//std::unique_ptr<UnitsAttributes> UnitsAttributes::clone()
//{
//	return std::make_unique<UnitsAttributes>(*this);
//}

std::unique_ptr<MoveState> UnitsAttributes::getMoveState()
{
	return std::move(m_moveState);
}


