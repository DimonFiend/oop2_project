#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <utility>
#include "Unit.h"
#include "PlayerInventoryUI.h"
#include "array"
#include "typedefs.h"
#include "macros.h"
#include "BoardUI.h"

class Inventory {
public:
	Inventory();
	~Inventory() = default;

	void draw(sf::RenderWindow& window);
	bool isFull() const;
	void reduceInventoryCap() {m_InventoryCapacity--;};
	Unit* checkContain(const sf::Vector2f& point);
	void addHero(std::unique_ptr<Unit> hero);
	void placeUnit(const sf::Vector2f& point, BoardUI& board);
	int getBoardMaxCap() const { return m_boardMaxCapacity; };
	void placeInBoard(std::unique_ptr<Unit> unit);

	Units& getFighers();

private:
	int m_InventoryCapacity;
	int m_boardCapacity;
	int m_boardMaxCapacity;

	std::array<std::unique_ptr<Unit>, Macros::MAX_INV_SLOT> m_onSide;
	std::array<std::unique_ptr<Unit>, Macros::MAX_BOARD_SLOTS> m_onBoard;
	SelectedItem m_selectedContainer;
	std::unique_ptr<PlayerInventoryUI> m_inventoryUI;


	bool checkPlacableOnSide(const sf::Vector2f& point);
	bool checkPlacableOnBoard(const sf::Vector2f& point, BoardUI& board);
	void placeUnitOnSide(const sf::Vector2f& point);
	void placeUnitOnBoard(const sf::Vector2f& point, BoardUI& board);
	std::unique_ptr<Unit> getUnit();
	void returnUnit();
	void clearSelected();

};