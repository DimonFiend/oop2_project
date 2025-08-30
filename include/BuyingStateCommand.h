#pragma once
#include "Shop.h"
#include "GameData.h"
#include "GameController.h"
#include "ArenaState.h"

class BuyingStateCommand {

public:
    BuyingStateCommand() = default;
    virtual void execute() = 0;
    virtual ~BuyingStateCommand() = default;
};

class ToggleShopVisibility : public BuyingStateCommand {
public:
    ToggleShopVisibility(Shop& shop) : m_shop(shop), m_shopVisible(false) {}

    void execute() override
    {
        m_shopVisible = !m_shopVisible;
        m_shop.setVisible(m_shopVisible);
    }

private:
    Shop& m_shop;
    bool m_shopVisible;
};

class SwitchToFightState : public BuyingStateCommand {
    GameController& m_game;
    GameData& m_data;
    sf::RenderWindow& m_window;
public:
    SwitchToFightState(GameController& game, sf::RenderWindow& window, GameData& data)
        : m_game(game),m_window(window), m_data(data) {};

    virtual void execute() override
    {
        m_game.setState(std::make_unique<ArenaState>(m_game,m_window, m_data), true);
    }

};