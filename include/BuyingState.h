#pragma once
#include "GameData.h"
#include "GameState.h"
#include <map>
#include <array>
#include "Heroes.h"

class BuyingState : public GameState {
public:
	BuyingState(GameController& game, GameData& data);
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleInput(sf::Event& event, sf::RenderWindow& window) override;
	void handleMouse(const sf::Vector2f& mousePos);

private:
	void generateShop();

	GameData& m_data;
	std::map<int, std::string> m_shop;
	std::array<std::unique_ptr<Heroes>, 10> m_heroesShop;
	
};