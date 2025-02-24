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
	UnitRegistry();
	void OnUnitAdded(const std::shared_ptr<Actor>& actor);
	std::vector<std::shared_ptr<Actor>> GetPossibleTargets(std::shared_ptr<Actor>& unit);
	bool IsUnitsProcessable();
};

#endif	//SW_BATTLE_TEST_UNIT_REGISTRY_HPP
