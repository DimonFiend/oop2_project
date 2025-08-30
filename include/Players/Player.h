#pragma once
#include <string.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Inventory.h"
#include "typedefs.h"
#include "macros.h"
class Player
{

public:
	Player(const std::string& name) : m_health(Macros::PLAYER_MAX_HP), m_name(name), m_money(15) {};
	virtual ~Player() = default;

	void SetName(const std::string name) { m_name = name; };
	virtual void draw(sf::RenderWindow& window) = 0;

	void updateHealth(int lives) { m_health -= lives; };
	int getHealth() const { return m_health;};
	int& getHealth() { return m_health; };
	const std::string getName() const { return m_name; };
	const unsigned int& getMoney() const { return m_money; };
	bool hasSpace() const;
	bool checkContain(sf::Vector2f point);
	void reduceInventoryCap();

	void onRoundFinish(unsigned int val, int healthPenalty);
	const int& getCurrBoardCap() const { return m_inventory.getCurrBoardCap(); };
	const int& getBoardCap() const { return m_inventory.getBoardCap(); };
	void expandBoardLim();
	std::unique_ptr<BuyingStateUnit> makePurchase(std::unique_ptr<BuyingStateUnit> hero);
	Inventory& getInventory() { return m_inventory; };

	Units& getFighters();

private:
	std::string m_name;
	int m_health;
	Inventory m_inventory;
protected:
	unsigned int m_money;
};