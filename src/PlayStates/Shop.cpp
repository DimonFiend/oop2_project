#include "Shop.h"
#include "Player.h"

Shop::Shop(const sf::Vector2f& position)
    : m_shopUI(position), m_visible(false)
{
    m_hero[0] = "a";
    m_hero[1] = "b";
    m_hero[2] = "c";
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
        int random = rand() % 3;

        m_heroesShop[i] = std::move(HeroFactory::createHero("Heroes", m_hero[random], m_shopUI[i]));
    }
}