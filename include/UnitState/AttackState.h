#pragma once
#include "UnitState/UnitState.h"

class AttackState : public UnitState
{
public:
	AttackState() = default;
	virtual void Attack() = 0;
	virtual std::unique_ptr<AttackState> clone() const = 0;

private:


};