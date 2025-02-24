//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_SPAWN_SWORDSMAN_HANDLER_HPP
#define SW_BATTLE_TEST_SPAWN_SWORDSMAN_HANDLER_HPP

#include "CommandHandler.hpp"
#include "IO/Commands/SpawnSwordsman.hpp"

class SpawnSwordsmanHandler : public CommandHandler<sw::io::SpawnSwordsman>
{
public:
	void Handle(sw::io::SpawnSwordsman& command) override;
};

#endif	//SW_BATTLE_TEST_SPAWN_SWORDSMAN_HANDLER_HPP
