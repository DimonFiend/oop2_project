#pragma once
#include <string>
#include <memory>
#include "HeroFactory.h"
#include "UnitState/MoveState.h"
#include "UnitState/AttackState.h"

struct Attributes
{
	unsigned int m_attack = 0;
	unsigned int m_health = 0;
	unsigned int m_speed = 0;
	unsigned int m_cost = 0;
	unsigned int m_attackRange = 0;
	float m_attackSpeed = 0;
};

class UnitsAttributes {
private:
	
	Attributes m_attributes;
	std::string m_name;

protected:
	void setAttack(unsigned int attack);
	void setHealth(unsigned int health);
	void setSpeed(unsigned int speed);
	void setCost(unsigned int cost);
	void setAttackRange(unsigned int attackRange);
	void setName(const std::string& name);
	void setAttackSpeed(float attSpeed);
	std::unique_ptr<MoveState> m_moveState = nullptr;
	std::unique_ptr<AttackState> m_attackState = nullptr;


public:
	UnitsAttributes() = default;
	virtual ~UnitsAttributes() = default;

	const unsigned int getAttack() const;
	const unsigned int getHealth() const;
	const unsigned int getSpeed() const;		
	const unsigned int getCost() const;
	const unsigned int getAttackRange() const;
	const float getAttackSpeed() const;
	const std::string getName() const;
	const Attributes getAttributes() const { return m_attributes; };

	std::unique_ptr<MoveState> getMoveState();
	std::unique_ptr<AttackState> getAttackState();
};