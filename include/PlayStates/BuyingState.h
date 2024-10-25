#pragma once
#include "Player.h"
#include "BoardUI.h"
#include "Inventory.h"
#include "GameData.h"
#include "typedefs.h"
#include "GameState.h"
#include <map>
#include <array>
#include "Button.h"
#include "Shop.h"

class BuyingState : public GameState {
public:
	BuyingState(GameController& game,sf::RenderWindow& window, GameData& data);
	virtual void update() override;
	virtual void draw() override;
	virtual void handleInput(sf::Event event) override;
	void handleMousePressed();
	void updateMousePressed();
	void handleHeroRelease();
private:
	Player& m_player;
	ComputerVector& m_computerVector;
	Inventory& m_inventory;
	BoardUI& m_board;

	sf::RenderWindow& m_window;
	BuyingStateUnit* m_selected;
	Shop m_shop;
	Button m_shopButton;
	Button m_readyButton;
};