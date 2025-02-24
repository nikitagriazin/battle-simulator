//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_GAME_COMMAND_MEDIATOR_HPP
#define SW_BATTLE_TEST_GAME_COMMAND_MEDIATOR_HPP

#include "CreateMapHandler.hpp"
#include "SpawnHunterHandler.hpp"
#include "SpawnSwordsmanHandler.hpp"
#include "UnitMarchHandler.hpp"

class GameCommandMediator
{
private:
	CreateMapHandler createMapHandler;
	SpawnSwordsmanHandler spawnSwordsmanHandler;
	SpawnHunterHandler spawnHunterHandler;
	UnitMarchHandler actorMarchHandler;

public:
	void ProcessCreateMapCommand(sw::io::CreateMap& command);
	void ProcessSpawnSwordsmanCommand(sw::io::SpawnSwordsman& command);
	void ProcessSpawnHunterCommand(sw::io::SpawnHunter& command);
	void ProcessMarchCommand(sw::io::March& command);
};

#endif	//SW_BATTLE_TEST_GAME_COMMAND_MEDIATOR_HPP

