//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_STATS_COMPONENT_HPP
#define SW_BATTLE_TEST_STATS_COMPONENT_HPP

#include "Core/ActorComponent.hpp"
#include "Units/StatType.hpp"

#include <unordered_map>

class StatsComponent : public ActorComponent
{
private:
	std::unordered_map<StatType, uint32_t> stats;

public:
	inline void SetStat(StatType key, uint32_t value)
	{
		stats[key] = value;
	}

	[[nodiscard]]
	inline uint32_t GetStat(StatType key, uint32_t default_value = 0) const
	{
		auto it = stats.find(key);
		return it != stats.end() ? it->second : default_value;
	}
};

#endif	//SW_BATTLE_TEST_STATS_COMPONENT_HPP
