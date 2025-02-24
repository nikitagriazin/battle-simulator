//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_HEALTH_COMPONENT_HPP
#define SW_BATTLE_TEST_HEALTH_COMPONENT_HPP

#include "Core/ActorComponent.hpp"

class HealthComponent : public ActorComponent
{
private:
	uint32_t currentHP;
	uint32_t maxHP;

public:
	explicit HealthComponent(uint32_t hp) :
			currentHP(hp),
			maxHP(hp)
	{}

	void ApplyDamage(int damage);

	[[nodiscard]]
	inline bool IsAlive() const
	{
		return currentHP != 0;
	}

	[[nodiscard]]
	inline uint32_t GetCurrentHP() const
	{
		return currentHP;
	}

	[[nodiscard]]
	inline uint32_t GetMaxHP() const
	{
		return maxHP;
	}
};

#endif	//SW_BATTLE_TEST_HEALTH_COMPONENT_HPP
