#pragma once
#include <string.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Inventory.h"
#include "typedefs.h"

class Player
{

public:
	Player(const std::string& name) : m_lives(100), m_name(name), m_money(100) {};
	virtual ~Player() = default;

	void SetName(const std::string name) { m_name = name; };
	const std::string GetName() const { return m_name; };
	virtual void draw(sf::RenderWindow& window) = 0;

	void UpdateLives(int lives) { m_lives -= lives; };
	int GetLives() const { return m_lives;};
	const unsigned int getMoney() const { return m_money; };

	bool hasSpace() const;
	bool checkContain(sf::Vector2f point);
	void reduceInventoryCap();

	std::unique_ptr<BuyingStateUnit> makePurchase(std::unique_ptr<BuyingStateUnit> hero);
	Inventory& getInventory() { return m_inventory; };

	Units& getFighters();

private:
	std::string m_name;
	int m_lives;
	Inventory m_inventory;
	unsigned int m_money;
};