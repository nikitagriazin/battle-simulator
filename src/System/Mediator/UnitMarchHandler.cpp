//
// Created by NikitaGriazin on 24.02.2025.
//

#include "UnitMarchHandler.hpp"

#include "Core/Actor.hpp"
#include "IO/System/PrintDebug.hpp"
#include "System/Simulation.hpp"
#include "Units/Components/PositionComponent.hpp"
#include "Utility/ServiceLocator.hpp"

void UnitMarchHandler::Handle(sw::io::March& command)
{
	auto simulation = ServiceLocator::GetInstance().Resolve<Simulation>();
	auto actor = simulation->GetObjectAs<Actor>(command.unitId);
	auto actorPositionComponent = actor->GetComponent<PositionComponent>();
	actorPositionComponent->MarchTo(Vector2(command.targetX, command.targetY));
}