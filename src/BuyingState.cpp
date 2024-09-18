#include "BuyingState.h"
#include "HeroFactory.h"
#include "GameObject.h"
#include "Heroes.h"

BuyingState::BuyingState(GameController& game, GameData& data) :GameState(game), m_data(data)
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

}

void BuyingState::draw(sf::RenderWindow& window)
{
	m_data.draw(window);
	window.setView(window.getDefaultView());

	for (int i = 0; i < m_heroesShop.size(); i++)
	{
		if (m_heroesShop[i])
		{
			m_heroesShop[i]->draw(window);
		}
	}
}

void BuyingState::handleInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		switch(event.mouseButton.button)
		{
		case sf::Mouse::Left:
			handleMouse(mousePos);
			break;
		}
	}
}

void BuyingState::handleMouse(const sf::Vector2f& mousePos)
{
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