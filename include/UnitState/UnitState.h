#pragma once
#include <memory>

class UnitState
{
public:
	UnitState() = default;
	virtual ~UnitState() {};

	virtual void update(const float dt) = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	

private:
};