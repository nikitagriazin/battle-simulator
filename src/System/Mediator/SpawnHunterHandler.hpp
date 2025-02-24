//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_SPAWN_HUNTER_HANDLER_HPP
#define SW_BATTLE_TEST_SPAWN_HUNTER_HANDLER_HPP

#include "CommandHandler.hpp"
#include "IO/Commands/SpawnHunter.hpp"

class SpawnHunterHandler : public CommandHandler<sw::io::SpawnHunter>
{
public:
	void Handle(sw::io::SpawnHunter& command) override;
};

#endif	//SW_BATTLE_TEST_SPAWN_HUNTER_HANDLER_HPP
