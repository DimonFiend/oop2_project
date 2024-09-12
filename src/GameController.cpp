#include "GameController.h"
#include "Settings.h"
#include "Board.h"
GameController::GameController(int w, int h, std::string title) {
	// Constructor implementation
	m_window.create(sf::VideoMode(w, h), title, sf::Style::Close);
	m_window.setFramerateLimit(60);
	m_view = m_window.getDefaultView();
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
	// Update implementation
}

void GameController::render()
{
	m_window.clear(sf::Color::Blue);
	Board board;
	board.draw(m_window);
	m_window.display();
}

void GameController::processEvents()
{
	//ze po zmani
	for (auto event = sf::Event{}; m_window.pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			break;
		}
	}
}

