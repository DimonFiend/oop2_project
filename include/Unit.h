#pragma once
#include "GameObject.h"
class Unit : public GameObject {

private:
	static bool m_bool_init;
	unsigned int m_cost;
	sf::Vector2f m_initPos;


	// Nisuim shel vadim
	sf::Vector2i m_indexOnBoard;
	//

public:
	Unit(const std::string& name, const sf::Vector2f& pos);
	virtual ~Unit() = default;
	unsigned int getCost() const { return m_cost; };
	void initPos() { getSprite().setPosition(m_initPos); };
	sf::Vector2f getInitPos() const { return m_initPos; };
	void setInitPos(const sf::Vector2f& pos) { m_initPos = pos; };

	// Nisuim shel vadim
	void setIndex(const sf::Vector2i& point);

	sf::Vector2i getIndex() const;
	sf::Vector2i getInverseIndex() const;
	//
};