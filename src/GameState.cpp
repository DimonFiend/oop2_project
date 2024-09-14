#include "GameState.h"
#include "GameController.h"

GameState::GameState(GameController& controller) : m_controller(controller)
{}

void GameState::setState(std::unique_ptr<GameState> NewState)
{
	m_controller.setState(std::move(NewState));
}