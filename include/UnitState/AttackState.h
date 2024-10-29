#pragma once
#include "UnitState/UnitState.h"

class AttackState : public UnitState
{
public:
	AttackState(float attSpeed) :m_attackSpeed(attSpeed) {};
	virtual void Attack() = 0;

protected:
	float m_attackDelay = 0;
	float m_attackSpeed;
};