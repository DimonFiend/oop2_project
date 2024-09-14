#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class GameController;
class GameState
{
public:
	GameState(GameController& controller);
	virtual ~GameState() = default;

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update() = 0;
	virtual void processEvents(sf::RenderWindow& window) = 0;
	void setState(std::unique_ptr<GameState> NewState);
private:
	GameController& m_controller;
};