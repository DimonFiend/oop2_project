/// \file    Controller.h
/// \brief   Header file for the Controller class.
/// the Controller class is responsible for the game loop and the game windows.

#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "GameData.h"
#include <memory>

//using State = std::unique_ptr<GameState>;

class GameController {
public:
	GameController(sf::RenderWindow&, std::string title);
	static void startGame(sf::RenderWindow &); // static function to run the game
	void setState(std::unique_ptr<GameState> state) { m_state = std::move(state);};
private:
	void run();
	void update();
	void render();
	void handleInput();

	sf::RenderWindow& m_window;
	GameData m_data;
	std::unique_ptr<GameState> m_state;
};