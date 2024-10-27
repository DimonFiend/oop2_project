/// \file    Controller.h
/// \brief   Header file for the Controller class.
/// the Controller class is responsible for the game loop and the game windows.

#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "GameData.h"
#include <memory>
#include "State.h"
#include "GamePanelUI.h"
#include <queue>
#include "PlayersStatusBar.h"

//using State = std::unique_ptr<GameState>;
class GameController : public State {
public:
	GameController(GameEngine& m_engine, sf::RenderWindow& window);
	void setState(std::unique_ptr<GameState> state, bool change);
	virtual void changeState();
	void update(const float dt);
	void draw();
	void handleInput(sf::Event event);
private:

	GameData m_data;
	GamePanelUI m_gameUI;
	sf::RenderWindow& m_window;
	std::vector<std::unique_ptr<GameState>> m_state;
	std::queue<std::pair<std::unique_ptr<GameState>, bool>> m_states_q;
	PlayersStatusBar m_PlayersStatus;
	sf::Sprite m_background;
};