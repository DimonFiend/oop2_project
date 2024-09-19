#include "Command.h"
#include "Menu.h"
#include <iostream>
#include "GameController.h"


void NewGame::execute() {
    srand(time(NULL));
    GameController::startGame();
}

void Settings::execute() {
    std::cout << "opening settings\n";

}

void Tutorial::execute() {
    std::cout << "opening Tutorial\n";

}


