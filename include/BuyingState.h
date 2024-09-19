#pragma once
#include "GameData.h"
#include "GameState.h"
#include <map>
#include <array>
#include "Heroes.h"

class BuyingState : public GameState {
public:
	BuyingState(GameController& game, sf::RenderWindow& window, GameData& data);
	virtual void update() override;
	virtual void draw() override;
	virtual void handleInput(sf::Event& event) override;
	void handleMouse();
	void handleMousePressed();
	void handleHeroRelease();
private:
	using SlotPair = std::pair<std::unique_ptr<Tile>, std::unique_ptr<Heroes>>;
	void generateShop();

	GameData& m_data;
	sf::RenderWindow& m_window;
	std::map<int, std::string> m_shop;
	std::array<std::unique_ptr<Heroes>, 10> m_heroesShop;
	SlotPair* m_selectedHero;
};