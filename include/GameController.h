/// \file    Controller.h
/// \brief   Header file for the Controller class.
/// the Controller class is responsible for the game loop and the game windows.


#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

using State = std::unique_ptr<GameState>;

class GameController {
public:
	GameController(int w, int h, std::string title);
	static void startGame(); // static function to run the game
	void setState(State state) { m_state = std::move(state); };
private:
	void run();
	void update();
	void render();
	void processEvents();

	sf::RenderWindow m_window;
	State m_state;
};