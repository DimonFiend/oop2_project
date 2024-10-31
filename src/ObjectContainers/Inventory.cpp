#include "Inventory.h"
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Tile.h"
#include "Settings.h"
#include "HeroFactory.h"


Inventory::Inventory() : m_InventoryCapacity(0), m_boardCapacity(0), m_boardMaxCapacity(Macros::INIT_BOARD_CAPACITY)
{
	auto start_pos = sf::Vector2f{ 0, static_cast<float>(Settings::Instance().getHeight()) / 7.f - 15};
	m_inventoryUI = std::make_unique<PlayerInventoryUI>(start_pos);
}

void Inventory::draw(sf::RenderWindow& window)
{
	m_inventoryUI->draw(window);
 	for (auto& items : m_onSide)
	{
		if (items)
		{
			items->draw(window);
		}
	}
	for (auto& items : m_onBoard)
	{
		if (items)
		{
			items->draw(window);
		}
	}
}

bool Inventory::isFull() const
{
	return m_InventoryCapacity == Macros::MAX_INV_SLOT;
}

BuyingStateUnit* Inventory::checkContain(const sf::Vector2f& point)
{
	for (auto& slot : m_onSide)
	{
		if (slot && slot->checkContain(point))
		{
			m_selectedContainer = std::make_pair(&m_onSide, slot.get());
			return slot.get();
		}
	}

	for (auto& slot : m_onBoard)
	{
		if (slot && slot->checkContain(point))
		{
			m_selectedContainer = std::make_pair(&m_onBoard, slot.get());
			return slot.get();
		}
	}

	return nullptr;
}

void Inventory::placeUnit(const sf::Vector2f& point, BoardUI& board)
{
	if(!m_selectedContainer.second) { return; }

	if(checkPlacableOnSide(point))
	{
		placeUnitOnSide(point);
		return;
	}
	else if(checkPlacableOnBoard(point, board))
	{
		placeUnitOnBoard(point, board);
		return;
	}

	returnUnit();
}

void Inventory::placeInBoard(std::unique_ptr<BuyingStateUnit> unit)
{
	for (auto& boardSlot : m_onBoard)
	{
		if (!boardSlot)
		{
			boardSlot = std::move(unit);
		}
	}
}

void Inventory::update(const float dtTime)
{
	for (auto& unit : m_onSide)
	{
		if (unit)
		{
			unit->update(dtTime);
		}
	}
	
	for (auto& unit : m_onBoard)
	{
		if (unit)
		{
			unit->update(dtTime);
		}
	}
}

Units& Inventory::getFighers()
{
	return m_onBoard;
}

void Inventory::expandBoardLim()
{
	m_boardMaxCapacity++;
}

bool Inventory::checkPlacableOnBoard(const sf::Vector2f& point)
{
	for(auto& onBoard : m_onBoard)
	{
		if(onBoard && onBoard->checkContain(point))
		{
			return false;
		}
	}
	return true;
}

void Inventory::placeUnitOnBoard(const sf::Vector2f& point, BoardUI& board)
{
	auto index = board.posToIndex(point);
	if (index.x < 0 || index.y < 0) { return; }
	m_selectedContainer.second->setPosition(board.indexToPos(index));
	m_selectedContainer.second->setInitPos(board.indexToPos(index));
	
	for (auto& onBoard : m_onBoard)
	{
		if (!onBoard)
		{
			if (&m_onBoard != m_selectedContainer.first)
			{
				// setting units place on board
				auto index = board.posToIndex(point);
				m_selectedContainer.second->setIndex(sf::Vector2i(index));
				//

				onBoard = std::move(getUnit());
				m_InventoryCapacity--;
				m_boardCapacity++;
			}

			clearSelected();
			return;
		}
	}
}

void Inventory::placeUnitOnSide(const sf::Vector2f& point)
{
	if(!m_selectedContainer.second) { return; }

	if (checkPlacableOnSide(point))
	{
		auto index = m_inventoryUI->posToIndex(point);
		m_selectedContainer.second->setPosition((*m_inventoryUI)[index]);
		m_selectedContainer.second->setInitPos((*m_inventoryUI)[index]);
		m_onSide[index] = std::move(getUnit());

		if (&m_onSide != m_selectedContainer.first)
		{
			m_InventoryCapacity++;
			m_boardCapacity--;
		}
	}

	clearSelected();
}

std::unique_ptr<BuyingStateUnit> Inventory::getUnit()
{
	for(auto it = m_selectedContainer.first->begin(); it != m_selectedContainer.first->end(); it++)
	{
		if(it->get() && it->get() == m_selectedContainer.second)
		{
			return std::move(*it);
		}
	}

	return nullptr;
}

void Inventory::returnUnit()
{
	if(!m_selectedContainer.second){return;}

	m_selectedContainer.second->initPos();
	clearSelected();

}

void Inventory::clearSelected()
{
	m_selectedContainer.first = nullptr;
	m_selectedContainer.second = nullptr;
}

//check if the unit can be placed in the backpack
bool Inventory::checkPlacableOnSide(const sf::Vector2f& point)
{
	//placable in the inventory
	if(m_inventoryUI->checkContain(point))
	{
		int index = m_inventoryUI->posToIndex(point);
		if (index < 0) { throw std::out_of_range("Bad index to place in inventory"); }
		return !isFull() && !m_onSide[index];
	}
	return false;
}

bool Inventory::checkPlacableOnBoard(const sf::Vector2f& point, BoardUI& board)
{
	auto index = board.posToIndex(point);
	for (auto& onBoard : m_onBoard)
	{
		if (onBoard)
		{
			auto indexHero = board.posToIndex(onBoard->getInitPos());
			if (index == indexHero) return false;
		}
	}

	if (!board.checkContain(point)) return false;

	if (&m_onBoard != m_selectedContainer.first &&
		m_boardCapacity == m_boardMaxCapacity)
		return false;

	return true;
}

void Inventory::addHero(std::unique_ptr<BuyingStateUnit> hero)
{
	for(int i = 0; i < Macros::MAX_INV_SLOT; i++)
	{
		if(!m_onSide[i])
		{
			hero->setPosition((*m_inventoryUI)[i]);
			hero->setInitPos((*m_inventoryUI)[i]);
			m_onSide[i] = std::move(hero);
			m_InventoryCapacity++;
			return;
		}
	}
}