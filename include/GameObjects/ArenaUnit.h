#pragma once
#include "GameObject.h"
#include "UnitState/MoveState.h"
#include "UnitState/AttackState.h"
#include "UnitsAttributes.h"
#include "HpBar.h"
#include "Animation.h"
#include "CharacterActions.h"

typedef std::unique_ptr<AttackState> attackState;
typedef std::unique_ptr<MoveState> moveState;
typedef std::unique_ptr<UnitsAttributes> unitAttributes;

enum state
{
	Move, Attack, Death,Idle
};

class ArenaUnit : public GameObject
{
	//attackState m_attackState;
	moveState m_moveState;
	attackState m_attackState;

	UnitState* m_currentState;

	bool m_leftTeam;
	bool m_toChange;
	state m_next;

	std::string m_name;
	HpBar m_hpBar;

	const Attributes m_attributes;
	Animation m_animation;

	ArenaUnit* m_target;
public:

	ArenaUnit(unitAttributes attributes, const sf::Vector2f& pos, CombatState& combat);

	void draw(sf::RenderWindow& window) override;
	void update(const float dt);
	void switchState(const state s);
	void requestSwitchState(const state s);

	void flipUnit();
	void flipTeam() { m_leftTeam = !m_leftTeam; }
	void changeHP(const int hp);
	bool getTeam() const { return m_leftTeam; }
	const Attributes& getAttributes() const { return m_attributes; }
	void move(const sf::Vector2f direction);
	unsigned int getAttackRange() const { return m_attributes.m_attackRange; };
	bool isAlive() const { return m_hpBar.getHP() > 0;}
	void setTarget(ArenaUnit* target) { this->m_target = target; }
	ArenaUnit* getTarget() { return m_target; }
};
