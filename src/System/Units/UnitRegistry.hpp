//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_UNIT_REGISTRY_HPP
#define SW_BATTLE_TEST_UNIT_REGISTRY_HPP

#include "Core/Actor.hpp"
#include "Units/Components/BehaviourLogicComponent.hpp"
#include "Units/Components/HealthComponent.hpp"
#include "Units/Components/PositionComponent.hpp"

#include <map>

struct UnitRegistryEntry
{
	uint32_t id;
	std::weak_ptr<Actor> actor;
	std::weak_ptr<PositionComponent> positionComponent;
};

class UnitRegistry
{
private:
	std::vector<UnitRegistryEntry> registry;

public:
	UnitRegistry() :
			registry({})
	{}

	void OnUnitAdded(const std::shared_ptr<Actor>& actor)
	{
		auto posComponent = actor->GetComponent<PositionComponent>();
		if (posComponent)
		{
			registry.push_back({actor->GetId(), actor, posComponent});
		}
	}

	std::vector<std::shared_ptr<Actor>> GetPossibleTargets(std::shared_ptr<Actor>& unit)
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

	bool IsUnitsProcessable()
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
};

#endif	//SW_BATTLE_TEST_UNIT_REGISTRY_HPP
