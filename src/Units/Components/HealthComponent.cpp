//
// Created by NikitaGriazin on 02.02.2025.
//

#include "HealthComponent.hpp"

#include "Utility/ServiceDefines.hpp"
#include "Core/Actor.hpp"

#include <algorithm>

void HealthComponent::ApplyDamage(int damage) {
	if (!IsAlive()) {
		return;
	}

	if (damage > 0) {
		currentHP = std::clamp(currentHP > damage ? currentHP - damage : 0, 0u, maxHP);
	}

	if (!IsAlive()) {
		ServiceLocator::GetInstance().Resolve<SimulationLog>()->log(sw::io::UnitDied(GetOwner()->GetId()));
	}
}
