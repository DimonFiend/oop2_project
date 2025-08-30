#pragma once
#include "AttackState.h"

class MeleeAttack : public AttackState {
public:
	MeleeAttack(float attackSpeed);
	virtual void onEnter();
	virtual void onExit();
	virtual void Attack();
};