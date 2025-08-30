#include "State.h"
#include "GameEngine.h"
#include <iostream>

State::State(GameEngine& engine) : m_engine(engine) {};

void State::nextState(std::unique_ptr<State> state, bool change) {
	m_engine.setState(std::move(state), change);
};