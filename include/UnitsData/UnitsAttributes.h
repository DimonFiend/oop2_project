#pragma once
#include <string>
#include <memory>
#include "HeroFactory.h"
#include "UnitState/MoveState.h"

class UnitsAttributes {
public:
	UnitsAttributes() = default;
	virtual ~UnitsAttributes() = default;

	virtual const unsigned int getAttack() const;
	virtual const unsigned int getHealth() const;
	virtual const unsigned int getSpeed() const;
	virtual const unsigned int getCost() const;
	virtual const unsigned int getAttackRange() const;
	virtual const std::string getName() const;
	//virtual std::unique_ptr<UnitsAttributes> clone();

	std::unique_ptr<MoveState> getMoveState();

protected:
	void setAttack(unsigned int attack);
	void setHealth(unsigned int health);
	void setSpeed(unsigned int speed);
	void setCost(unsigned int cost);
	void setAttackRange(unsigned int attackRange);
	void setName(const std::string& name);

	std::unique_ptr<MoveState> m_moveState;

private:
	unsigned int m_attack;
	unsigned int m_health;
	unsigned int m_speed;
	unsigned int m_cost;
	unsigned int m_attackRange;
	std::string m_name;

	
};