#pragma once
#include <memory>

class CombatState;
class ArenaUnit;

class UnitState
{
public:
	UnitState() : m_unit(nullptr), m_combatManager(nullptr) {};
	virtual ~UnitState() {};

	virtual void update(const float dt) = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	
	void setUnit(ArenaUnit& unit) { m_unit = &unit; };
	void setManager(CombatState& manager) { m_combatManager = &manager; };

protected:

	ArenaUnit* m_unit;
	CombatState* m_combatManager;
};