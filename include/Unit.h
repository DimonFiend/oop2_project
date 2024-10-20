#pragma once
#include "GameObject.h"
#include "UnitState/MoveState.h"
#include "UnitState/AttackState.h"

typedef std::unique_ptr<AttackState> attackState;
typedef std::unique_ptr<MoveState> moveState;

enum state
{
	Move, Attack
};

class Unit : public GameObject {

private:

	void switchState(const state s);


	static bool m_bool_init;
	unsigned int m_cost;
	sf::Vector2f m_initPos;


	// Nisuim shel vadim
	sf::Vector2i m_indexOnBoard;

	//attackState m_attackState;
	moveState m_moveState;
	UnitState* m_currentState;

	bool m_toChange;
	state m_next;
	//

public:

	Unit(const std::string& name, const sf::Vector2f& pos);
	virtual ~Unit() = default;
	Unit(const Unit& other);

	unsigned int getCost() const { return m_cost; };
	void initPos() { getSprite().setPosition(m_initPos); };
	sf::Vector2f getInitPos() const { return m_initPos; };
	void setInitPos(const sf::Vector2f& pos) { m_initPos = pos; };

	// Nisuim shel vadim

	void update(const float dt);
	void requestSwitchState(const state s);
	void setIndex(const sf::Vector2i& point);

	sf::Vector2i getIndex() const;
	sf::Vector2i getInverseIndex() const;
	//
};