//
// Created by NikitaGriazin on 03.02.2025.
//

#ifndef SW_BATTLE_TEST_ALWAYS_TRUE_CONDITION_HPP
#define SW_BATTLE_TEST_ALWAYS_TRUE_CONDITION_HPP

#include "Core/Condition.hpp"
class AlwaysTrueCondition : public Condition {
public:
	[[nodiscard]]
	inline bool isPassed(const std::any& argument) const override
	{
		return true;
	}
};

#endif	//SW_BATTLE_TEST_ALWAYS_TRUE_CONDITION_HPP
