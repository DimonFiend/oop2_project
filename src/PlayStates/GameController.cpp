#include "GameController.h"
#include "Settings.h"
#include "BuyingState.h"
#include "ArenaState.h"
#include "GameEngine.h"
#include "Resources.h"

GameController::GameController(GameEngine& engine, sf::RenderWindow& window)
    : State(engine),
    m_window(window),
    m_PlayersStatus(m_data),
    m_gameUI(*m_data.getPlayer())
{
    // Constructor implementation
   m_state.push_back(std::make_unique<BuyingState>(*this, m_window, m_data));
   m_background.setTexture(Resources::Instance().getTexture("ForestBG"));
   auto size = m_background.getTexture()->getSize();
   m_background.setScale(float(Settings::Instance().getWidth()) / size.x, float(Settings::Instance().getHeight()) / size.y);
}

void GameController::setState(std::unique_ptr<GameState> state, bool change)
{
    m_states_q.push(std::make_pair(std::move(state), change));
}

void GameController::changeState()
{
    if (!m_states_q.empty())
    {
        if (m_states_q.front().second)
        {
            m_state.pop_back();
            m_state.push_back(std::move(m_states_q.front().first));
            m_states_q.pop();
        }
    }
}


void GameController::update(const float dt)
{
    for (auto it = m_state.rbegin(); it != m_state.rend(); it++)
    {
        (*it)->update(dt);
    }
    m_PlayersStatus.update();
}

void GameController::draw()
{
	m_window.draw(m_background);
	m_gameUI.draw(m_window);
    m_PlayersStatus.draw(m_window);

    for (auto it = m_state.rbegin(); it != m_state.rend(); it++)
    {
        (*it)->draw();
    }
}


void GameController::handleInput(sf::Event event)
{
    for (auto it = m_state.rbegin(); it != m_state.rend(); it++)
    {
        (*it)->handleInput(event);
    }
}
