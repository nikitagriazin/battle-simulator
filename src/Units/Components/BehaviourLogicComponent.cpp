//
// Created by NikitaGriazin on 02.02.2025.
//

#include "BehaviourLogicComponent.hpp"

#include <utility>

BehaviourLogicComponent::BehaviourLogicComponent() :
		isNoAvailableActions(false)
{}

void BehaviourLogicComponent::Activate()
{
	healthComponent = GetOwner()->GetComponent<HealthComponent>();
}

void BehaviourLogicComponent::AddBehavior(const std::shared_ptr<Behaviour>& behaviour, int priority)
{
	behaviour->SetOwner(GetOwner());
	behaviorPriorities[priority] = behaviour;
}

void BehaviourLogicComponent::Tick(uint32_t tick)
{
	if (!healthComponent->IsAlive())
	{
		return;	 // Died units have no logic
	}

	for (auto& [priority, behaviour] : behaviorPriorities)
	{
		if (behaviour->CanRun())
		{
			if (currentBehavior)
			{
				currentBehavior->Terminate();
			}
			currentBehavior = behaviour;
			currentBehavior->Initialize();
			break;
		}
	}
	currentBehavior->Tick(tick);
}
