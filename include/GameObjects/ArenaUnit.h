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
	Move, Attack
};

class ArenaUnit : public GameObject
{
	//attackState m_attackState;
	moveState m_moveState;
	UnitState* m_currentState;

	bool m_leftTeam;
	bool m_toChange;
	state m_next;

	std::string m_name;
	HpBar m_hpBar;

	Animation m_animation;
public:

	ArenaUnit(unitAttributes attributes, const sf::Vector2f& pos, CombatState& combat);

	void draw(sf::RenderWindow& window) override;
	void update(const float dt);
	void switchState(const state s);
	void requestSwitchState(const state s);

	void flipUnit() { getSprite().setScale(-1, 1); };
	void flipTeam() { m_leftTeam = false; }

	bool getTeam() const { return m_leftTeam; }

	void move(const sf::Vector2f direction);
};
