#include "GameEngine.h"
#include "Settings.h"
#include "GameState.h"
#include "Menu.h"
#include "GameController.h"
#include <iostream>

GameEngine::GameEngine()
{
	sf::VideoMode mode = {Settings::Instance().getWidth(), Settings::Instance().getHeight()};
	m_window.create(mode, "Little Auto Chess", sf::Style::Close);
	m_window.setFramerateLimit(60);
	m_states.push(std::make_unique<GameController>(*this, m_window));
}

void GameEngine::setState(std::unique_ptr<State> state, bool change)
{
	m_states_q.push(std::make_pair(std::move(state), change));
}

void GameEngine::run()
{
	sf::Clock m_deltaClock;
	float dt;
	while (m_window.isOpen() && !m_states.empty())
	{
		dt = m_deltaClock.restart().asSeconds();
		handleInput();
		update(dt);
		render();
		changeState();
	}
}

void GameEngine::update(const float dt)
{
	m_states.top()->update(dt);
}

void GameEngine::render()
{
	m_window.clear();
	m_states.top()->draw();
	m_window.display();
}

void GameEngine::handleInput()
{
	for(sf::Event event; m_window.pollEvent(event);)
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		m_states.top()->handleInput(event);
	}
}

void GameEngine::changeState()
{
	if (!m_states_q.empty())
	{
		if (m_states_q.front().second)
		{
			m_states.pop();
		}
		m_states.push(std::move(m_states_q.front().first));
		m_states_q.pop();
	}

	if (m_states.top())
	{
		m_states.top()->changeState();
	}
}
