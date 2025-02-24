//
// Created by NikitaGriazin on 24.02.2025.
//

#include "SpawnSwordsmanHandler.hpp"

#include "IO/Events/UnitSpawned.hpp"
#include "IO/System/PrintDebug.hpp"
#include "System/Simulation.hpp"
#include "System/Units/UnitFactory.hpp"
#include "Utility/ServiceDefines.hpp"
#include "Utility/ServiceLocator.hpp"

void SpawnSwordsmanHandler::Handle(sw::io::SpawnSwordsman& command)
{
	auto position = Vector2(command.x, command.y);
	auto swordsman = UnitFactory::SpawnSwordsman(
		command.unitId, position, command.hp, command.strength);

	auto simulation = ServiceLocator::GetInstance().Resolve<Simulation>();
	simulation->AddObject(command.unitId, swordsman);

	ServiceLocator::GetInstance().Resolve<UnitRegistry>()->OnUnitAdded(swordsman);

	ServiceLocator::GetInstance().Resolve<SimulationLog>()->log(sw::io::UnitSpawned{command.unitId, "Swordsman", command.x, command.y});
}