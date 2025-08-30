#pragma once
#include "UnitState/UnitState.h"

class AttackState : public UnitState
{
public:
	AttackState(float attSpeed) :m_attackSpeed(attSpeed) {};
	virtual void Attack() = 0;
	virtual void update(const float dt);
	virtual void onEnter();
	virtual void onExit();
protected:
	float m_attackDelay = 0;
	float m_attackSpeed;
};