#include "BuyingState.h"
#include "HeroFactory.h"
#include "GameObject.h"
#include "BuyingStateCommand.h"

#include "GameController.h"
#include "PlayStates/CombatState.h"

BuyingState::BuyingState(GameController& game, sf::RenderWindow& window, GameData& data)
	:GameState(game),
	m_player(*data.getPlayer()),
	m_computerVector(data.getComputerPlayers()),
	m_inventory(m_player.getInventory()),
	m_board(*data.getBoard()),
	m_window(window),
	m_selected(nullptr),
	m_shop({ (m_window.getSize().x / 2.f),300.f }),

	m_shopButton("shopslot", sf::Vector2f(window.getSize().x - 50, window.getSize().y - 50),
		std::bind(&ToggleShopVisibility::execute, std::make_shared<ToggleShopVisibility>(m_shop))),

	m_readyButton("shopslot", sf::Vector2f(window.getSize().x / 2, window.getSize().y - 50),
		std::bind(&SwitchToFightState::execute, std::make_shared<SwitchToFightState>(game, window, data)))
{}	

void BuyingState::update(const float)
{
	updateMousePressed();
}

void BuyingState::draw()
{
	m_board.draw(m_window);
	m_inventory.draw(m_window);
	m_player.draw(m_window);
	m_shop.draw(m_window);
	m_shopButton.draw(m_window);
	m_readyButton.draw(m_window);
	if(m_selected)
	{
		m_selected->draw(m_window);
	}
}

void BuyingState::handleInput(sf::Event event)
{
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));

	if (event.type == sf::Event::MouseButtonReleased)
	{
		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			handleHeroRelease();
			m_shopButton.handleClick(mousePos);
			m_readyButton.handleClick(mousePos);
			m_shop.handleClick(mousePos, &m_player);
			break;
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			handleMousePressed();
			break;
		}
	}
}

void BuyingState::handleMousePressed()
{
	if (m_selected) return;
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
	m_selected = m_inventory.checkContain(mousePos);

}

void BuyingState::updateMousePressed()
{
	if(m_selected)
	{
		sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
		m_selected->setPosition(mousePos);
	}
}

void BuyingState::handleHeroRelease()
{
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
	m_inventory.placeUnit(mousePos, m_board);
	m_selected = nullptr;
}
