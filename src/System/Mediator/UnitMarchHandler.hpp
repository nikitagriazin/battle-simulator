//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_UNIT_MARCH_HANDLER_HPP
#define SW_BATTLE_TEST_UNIT_MARCH_HANDLER_HPP

#include "CommandHandler.hpp"
#include "IO/Commands/March.hpp"

class UnitMarchHandler : public CommandHandler<sw::io::March>
{
public:
	void Handle(sw::io::March& command) override;
};

#endif	//SW_BATTLE_TEST_UNIT_MARCH_HANDLER_HPP
