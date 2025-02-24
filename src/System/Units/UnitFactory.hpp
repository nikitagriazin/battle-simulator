//
// Created by NikitaGriazin on 20.02.2025.
//

#ifndef SW_BATTLE_TEST_UNIT_FACTORY_HPP
#define SW_BATTLE_TEST_UNIT_FACTORY_HPP

#include "Core/Actor.hpp"
#include "Utility/Vector2.hpp"

#include <memory>

class UnitFactory
{
public:
	static std::shared_ptr<Actor> SpawnSwordsman(
		uint32_t unitId, Vector2 position, uint32_t hp, uint32_t strength);
	static std::shared_ptr<Actor> SpawnHunter(
		uint32_t unitId, Vector2 position, uint32_t hp, uint32_t agility, uint32_t strength, uint32_t range);
};

#endif	//SW_BATTLE_TEST_UNIT_FACTORY_HPP

