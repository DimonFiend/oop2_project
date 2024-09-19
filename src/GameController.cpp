#include "GameController.h"
#include "Settings.h"
#include "BuyingState.h"

GameController::GameController(int w, int h, std::string title)
{
	// Constructor implementation
	m_window.create(sf::VideoMode(w, h), title, sf::Style::Close);
	m_window.setFramerateLimit(60);
	this->setState(std::make_unique<BuyingState>(*this,m_window, m_data));

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
		handleInput();
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
	m_state->draw();
	m_window.display();
}

void GameController::handleInput()
{
	for (sf::Event event; m_window.pollEvent(event);)
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}

		m_state->handleInput(event);
	}
	
}

