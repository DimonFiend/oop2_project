#include "BuyingState.h"
#include "HeroFactory.h"
#include "GameObject.h"
#include "Heroes.h"

BuyingState::BuyingState(GameController& game, sf::RenderWindow& window, GameData& data) 
	:GameState(game), m_data(data), m_window(window), m_selectedHero(nullptr)
{ 
	m_shop[0] = "a";
	m_shop[1] = "b";
	m_shop[2] = "c";
	generateShop();
}

void BuyingState::generateShop()
{
	for (int i = 0; i < m_heroesShop.size(); i++)
	{
		int random = rand() % 3;

		sf::Vector2f pos(100 + i * 100, 100);
		m_heroesShop[i] = std::move(HeroFactory::createHero("Heroes", m_shop[random], pos));
	}
}	

void BuyingState::update()
{
	handleMousePressed();
}

void BuyingState::draw()
{
	m_data.draw(m_window);

	for (int i = 0; i < m_heroesShop.size(); i++)
	{
		if (m_heroesShop[i])
		{
			m_heroesShop[i]->draw(m_window);
		}
	}
}

void BuyingState::handleInput(sf::Event& event)
{
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));

	if (event.type == sf::Event::MouseButtonReleased)
	{
		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			handleMouse();
			handleHeroRelease();
			break;
		}
	}

	if(event.type == sf::Event::MouseButtonPressed)
	{
		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			m_selectedHero = m_data.checkContain(mousePos);
			break;
		}
	}
}

void BuyingState::handleMouse()
{
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));

	for(int i = 0; i < m_heroesShop.size(); i++)
	{
		if(m_heroesShop[i] && m_heroesShop[i]->checkContain(mousePos))
		{
			if(m_data.checkPurchase(m_heroesShop[i].get()))
			{
				m_data.makePurchase(std::move(m_heroesShop[i]));
			}
		}
	}
}

void BuyingState::handleMousePressed()
{
	if(m_selectedHero && m_selectedHero->second)
	{
		sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
		m_selectedHero->second->setPosition(mousePos);
	}
}

void BuyingState::handleHeroRelease()
{
	if (m_selectedHero && m_selectedHero->second)
	{
		if (!m_data.placeOnBoard(m_selectedHero))
		{
			m_selectedHero->second->initPos();
		}
		else
		{
			m_data.reduceInventoryCap();
		}
	}

	m_selectedHero = nullptr;
}
