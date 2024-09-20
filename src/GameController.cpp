#include "GameController.h"
#include "Settings.h"
#include "BuyingState.h"

GameController::GameController(sf::RenderWindow& window, std::string title)
    : m_window(window)  // Initialize m_window reference
{
    // Constructor implementation
    this->setState(std::make_unique<BuyingState>(*this, m_data));
    m_window.setFramerateLimit(60);
}

void GameController::startGame(sf::RenderWindow& window)
{
    GameController controller(window, "Little Auto Chess");
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
    m_state->draw(m_window);
    m_window.display();
    m_window.setView(m_window.getDefaultView());
}

void GameController::handleInput()
{
    for (sf::Event event; m_window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }

        m_state->handleInput(event, m_window);
    }
}
