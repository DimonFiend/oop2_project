#include "Shop.h"
#include "Player.h"
#include "BuyingStateUnit.h"
#include "HeroFactory.h"

Shop::Shop(const sf::Vector2f& position)
    : m_shopUI(position), m_visible(false)
{
    generateHeroes();
}

void Shop::draw(sf::RenderWindow& window) {
    if (m_visible) {
        m_shopUI.draw(window);
        for (int i = 0; i < m_heroesShop.size(); i++) {
            if (m_heroesShop[i]) {
                m_heroesShop[i]->draw(window);
            }
        }
    }
}

void Shop::setVisible(bool visible) {
    m_visible = visible;
}

void Shop::handleClick(sf::Vector2f mousePos, Player* player)
{
    if(!m_visible) return;
    for(int i = 0; i < m_heroesShop.size(); i++)
	{
		if(m_heroesShop[i] && m_heroesShop[i]->checkContain(mousePos))
		{
			m_heroesShop[i] = player->makePurchase(std::move(m_heroesShop[i]));
		}
	}
}

void Shop::generateHeroes() {
    for (int i = 0; i < m_heroesShop.size(); i++)
    {
        int random = rand() % 2;

        if (random % 2 == 0)
        {
            m_heroesShop[i] = std::move(HeroFactory::createBuyingPhaseHero("Sorcerer", m_shopUI[i]));
        }
        else
        {
            m_heroesShop[i] = std::move(HeroFactory::createBuyingPhaseHero("Dennis", m_shopUI[i]));
        }
    }
}