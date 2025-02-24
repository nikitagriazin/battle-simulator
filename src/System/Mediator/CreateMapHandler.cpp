//
// Created by NikitaGriazin on 24.02.2025.
//

#include "CreateMapHandler.hpp"

#include "IO/System/PrintDebug.hpp"
#include "System/Map.hpp"
#include "Utility/ServiceLocator.hpp"

void CreateMapHandler::Handle(sw::io::CreateMap& command)
{
	auto map = ServiceLocator::GetInstance().Resolve<Map>();
	map->InitMap(command.width, command.height);
}