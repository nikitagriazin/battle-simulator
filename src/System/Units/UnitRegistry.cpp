//
// Created by NikitaGriazin on 24.02.2025.
//

#include "UnitRegistry.hpp"

UnitRegistry::UnitRegistry() :
		registry({})
{}

void UnitRegistry::OnUnitAdded(const std::shared_ptr<Actor>& actor)
{
	auto posComponent = actor->GetComponent<PositionComponent>();
	if (posComponent)
	{
		registry.push_back({actor->GetId(), actor, posComponent});
	}
}

std::vector<std::shared_ptr<Actor>> UnitRegistry::GetPossibleTargets(std::shared_ptr<Actor>& unit)
{
	std::vector<std::shared_ptr<Actor>> result;
	for (auto & it : registry)
	{
		auto actor = it.actor.lock();
		if (unit != actor)
		{
			auto healthComponent = actor->GetComponent<HealthComponent>();
			if (!healthComponent->IsAlive()) {
				continue;
			}

			result.push_back(actor);
		}
	}
	return result;
}

bool UnitRegistry::IsUnitsProcessable()
{
	bool isAnyProcessable = false;
	int aliveUnitsCount = 0;
	for (auto it = registry.begin(); it != registry.end(); it++)
	{
		auto actor = it->actor.lock();
		auto logicComponent = actor->GetComponent<BehaviourLogicComponent>();
		if (!logicComponent->IsNoAvailableActions())
		{
			isAnyProcessable = true;
		}

		auto healthComponent = actor->GetComponent<HealthComponent>();
		if (healthComponent->IsAlive())
		{
			aliveUnitsCount++;
		}
	}
	return aliveUnitsCount > 1 && isAnyProcessable;
}