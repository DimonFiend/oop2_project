#include "Command.h"
#include "Menu.h"
#include <iostream>
#include "GameController.h"
#include <memory>

void NewGame::execute(Menu* adapter)
{
	if (adapter == nullptr)
    {
		std::cout << "adapter is null\n";
	}
    adapter->nextState(std::make_unique<GameController>(m_engine, m_window), true);
}

void SettingsMenu::execute(Menu* adapter) {
    std::cout << "opening settings\n";

}

void TutorialMenu::execute(Menu* adapter) {
    std::cout << "opening Tutorial\n";

}


