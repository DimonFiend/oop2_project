/// \file    Controller.h
/// \brief   Header file for the Controller class.
/// the Controller class is responsible for the game loop and the game windows.


#pragma once
#include <SFML/Graphics.hpp>

class GameController {
	///=======================================================================
public:
	GameController(int w, int h, std::string title);
	static void startGame(); // static function to run the game

private:
	void run();
	void update();
	void render();
	void processEvents();

	sf::RenderWindow m_window;
	sf::View m_view;
};