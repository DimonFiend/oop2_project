#pragma once
#include "AttackState.h"

class RangedAttack : public AttackState
{
	std::string m_obj;
public:
	RangedAttack(float attackSpeed, const std::string& obj);
	virtual void onEnter();
	virtual void onExit();
	virtual void Attack();
};