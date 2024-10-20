#pragma once
#include "UnitState/MoveState.h"



class MoveToClosest : public MoveState
{
public:
	MoveToClosest(sf::Sprite& sprite, const float speed);
	MoveToClosest(const MoveToClosest& other) = default;
	std::unique_ptr<MoveState> clone(sf::Sprite& sprite) const override;

	void update(const float dt) override;
	void onEnter() override;
	void onExit() override;
private:
};