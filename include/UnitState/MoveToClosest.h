#pragma once
#include "UnitState/MoveState.h"

class ArenaUnit;

class MoveToClosest : public MoveState
{
public:

	MoveToClosest(const float speed);
	MoveToClosest(const MoveToClosest& other) = default;

	void update(const float dt) override;
	void onEnter() override;
	void onExit() override;

private:
	void FindTarget();
	float calcDistance(ArenaUnit* target);
};