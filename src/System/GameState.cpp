//
// Created by NikitaGriazin on 24.02.2025.
//

#include "GameState.hpp"

GameState::GameState() :
		tick(1),
		isActive(false)
{}

void GameState::SetIsActive(bool active)
{
	isActive = active;
}

void GameState::Tick()
{
	tick++;
}