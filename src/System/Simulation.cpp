//
// Created by NikitaGriazin on 14.02.2025.
//

#include "Simulation.hpp"

Simulation::Simulation(
	std::shared_ptr<GameState>& gameState,
	std::shared_ptr<DamageProcessor>& damageController,
	std::shared_ptr<UnitRegistry>& unitRegistry,
	std::shared_ptr<GameCommandQueue>& commandQueue) :
		objects(),
		gameState(gameState),
		damageController(damageController),
		unitRegistry(unitRegistry),
		commandQueue(commandQueue)
{}

void Simulation::AddObject(const uint32_t key, const std::shared_ptr<GameObject>& obj)
{
	obj->Initialize();
	objects[key] = obj;

	if (gameState->GetIsActive())
	{
		obj->Activate();
	}
}

bool Simulation::IsIdRegistered(const uint32_t key)
{
	return objects.contains(key);
}

void Simulation::Run()
{
	Activate();
	Process();
	Deactivate();
	Terminate();
}

void Simulation::Activate()
{
	gameState->SetIsActive(true);
	for (auto& gameObject : objects)
	{
		gameObject.second->Activate();
	}
	commandQueue->ProcessCommands();
}

void Simulation::Process()
{
	while (unitRegistry->IsUnitsProcessable())
	{
		gameState->Tick();
		for (auto& gameObject : objects)
		{
			gameObject.second->Tick(gameState->GetTick());
		}
		damageController->ApplyDamage();
		commandQueue->ProcessCommands();
	}
}

void Simulation::Deactivate()
{
	gameState->SetIsActive(false);
	for (auto& gameObject : objects)
	{
		gameObject.second->Deactivate();
	}
}

void Simulation::Terminate()
{
	for (auto& gameObject : objects)
	{
		gameObject.second->Terminate();
	}
}
