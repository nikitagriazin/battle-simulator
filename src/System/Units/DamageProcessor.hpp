//
// Created by NikitaGriazin on 20.02.2025.
//

#ifndef SW_BATTLE_TEST_DAMAGE_CONTROLLER_HPP
#define SW_BATTLE_TEST_DAMAGE_CONTROLLER_HPP

#include "Core/Actor.hpp"
#include "Units/Components/HealthComponent.hpp"

#include <queue>

struct DamageEvent
{
	std::weak_ptr<Actor> attacker;
	std::weak_ptr<Actor> target;
	int damage;
};

class DamageProcessor
{
private:
	std::queue<DamageEvent> events;

public:
	DamageProcessor();

	void RegisterDamage(const DamageEvent& event);
	void ApplyDamage();
};

#endif	//SW_BATTLE_TEST_DAMAGE_CONTROLLER_HPP
