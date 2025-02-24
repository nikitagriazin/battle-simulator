//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_CREATE_MAP_HANDLER_HPP
#define SW_BATTLE_TEST_CREATE_MAP_HANDLER_HPP

#include "CommandHandler.hpp"
#include "IO/Commands/CreateMap.hpp"

class CreateMapHandler : public CommandHandler<sw::io::CreateMap>
{
public:
	void Handle(sw::io::CreateMap& command) override;
};

#endif	//SW_BATTLE_TEST_CREATE_MAP_HANDLER_HPP
