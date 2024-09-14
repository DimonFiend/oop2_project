#include "GameController.h"
#include "Settings.h"
#include "Board.h"
#include "GameLevel.h"

GameController::GameController(int w, int h, std::string title) {
	// Constructor implementation
	this->setState(std::make_unique<GameLevel>(*this));
	m_window.create(sf::VideoMode(w, h), title, sf::Style::Close);
	m_window.setFramerateLimit(60);
}

void GameController::startGame()
{
	GameController controller(Settings::Instance().getHeight(), Settings::Instance().getWidth(), "Little Auto Chess");
	controller.run();
}

void GameController::run()
{

	while (m_window.isOpen())
	{
		render();
		processEvents();
		update();
	}
}

void GameController::update()
{
	m_state->update();
}

void GameController::render()
{
	m_window.clear();
	m_state->draw(m_window);
	m_window.display();
}

void GameController::processEvents()
{
	m_state->processEvents(m_window);
}

