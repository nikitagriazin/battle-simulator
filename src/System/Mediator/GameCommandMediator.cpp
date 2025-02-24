//
// Created by NikitaGriazin on 24.02.2025.
//

#include "GameCommandMediator.hpp"

void GameCommandMediator::ProcessCreateMapCommand(sw::io::CreateMap& command)
{
	createMapHandler.Handle(command);
}

void GameCommandMediator::ProcessSpawnSwordsmanCommand(sw::io::SpawnSwordsman& command)
{
	spawnSwordsmanHandler.Handle(command);
}

void GameCommandMediator::ProcessSpawnHunterCommand(sw::io::SpawnHunter& command)
{
	spawnHunterHandler.Handle(command);
}

void GameCommandMediator::ProcessMarchCommand(sw::io::March& command)
{
	actorMarchHandler.Handle(command);
}