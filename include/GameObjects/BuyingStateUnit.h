#pragma once
#include "GameObject.h"
#include "UnitsData/UnitsAttributes.h"

typedef std::unique_ptr<UnitsAttributes> unitAttributes;

class BuyingStateUnit : public GameObject {

private:
	sf::Vector2f m_initPos;
	sf::Vector2i m_indexOnBoard;
	unsigned int m_cost;
	std::string m_name;
public:

	BuyingStateUnit(unitAttributes attributes, const sf::Vector2f& pos);
	virtual ~BuyingStateUnit() = default;
	unsigned int getCost() const { return m_cost; };
	const std::string getName() const { return m_name; };

	sf::Vector2f getInitPos() const { return m_initPos; };
	sf::Vector2i getInverseIndex() const;
	void initPos() { getSprite().setPosition(m_initPos); };
	void setInitPos(const sf::Vector2f& pos) { m_initPos = pos; };
	void setIndex(const sf::Vector2i& point);

	sf::Vector2i getIndex() const;
};