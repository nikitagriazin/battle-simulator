//
// Created by NikitaGriazin on 24.02.2025.
//

#include "SpawnHunterHandler.hpp"

#include "IO/System/PrintDebug.hpp"
#include "System/Simulation.hpp"
#include "System/Units/UnitFactory.hpp"
#include "Utility/ServiceDefines.hpp"
#include "Utility/ServiceLocator.hpp"

void SpawnHunterHandler::Handle(sw::io::SpawnHunter& command)
{
	auto position = Vector2(command.x, command.y);
	auto hunter = UnitFactory::SpawnHunter(
		command.unitId, position, command.hp, command.agility, command.strength, command.range);

	auto simulation = ServiceLocator::GetInstance().Resolve<Simulation>();
	simulation->AddObject(command.unitId, hunter);

	ServiceLocator::GetInstance().Resolve<UnitRegistry>()->OnUnitAdded(hunter);
	ServiceLocator::GetInstance().Resolve<SimulationLog>()->log(sw::io::UnitSpawned{command.unitId, "Hunter", command.x, command.y});
}
