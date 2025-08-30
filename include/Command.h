#pragma once
#include <SFML/Graphics.hpp>
#include "GameEngine.h"

class Menu;
class Command {
public:
    virtual ~Command() {}
    virtual void execute(Menu* adapter) = 0;
};

class NewGame : public Command {
public:
    NewGame(GameEngine& engine ,sf::RenderWindow& window) : m_window(window), m_engine(engine) {};
    void execute(Menu* adapter) override;

private:
	GameEngine& m_engine;
    sf::RenderWindow& m_window;
};

class SettingsMenu : public Command {
public:
    void execute(Menu* adapter) override;
};

class TutorialMenu : public Command {
public:
    void execute(Menu* adapter) override;
};

