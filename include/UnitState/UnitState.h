#pragma once
#include <memory>
#include "Animation.h"
class CombatState;
class ArenaUnit;

class UnitState
{
public:
	UnitState() : m_unit(nullptr),
				m_combatManager(nullptr),
				m_target(nullptr),		
				m_animation(nullptr){};

	virtual ~UnitState() {};

	virtual void update(const float dt) = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	
	void setUnit(ArenaUnit& unit) { m_unit = &unit; };
	void setTarget(ArenaUnit& target) { m_target = &target; };
	void setManager(CombatState& manager) { m_combatManager = &manager; };
	void setAnimation(Animation& animation) { m_animation = &animation; };

protected:

	ArenaUnit* m_unit;
	ArenaUnit* m_target;
	CombatState* m_combatManager;
	Animation* m_animation;
};