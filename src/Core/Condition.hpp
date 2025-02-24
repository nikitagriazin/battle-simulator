//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_CONDITION_HPP
#define SW_BATTLE_TEST_CONDITION_HPP

#include <any>

class Condition
{
public:
	virtual ~Condition() = default;

	[[nodiscard]]
	virtual bool isPassed(const std::any& argument) const = 0;
};

#endif	//SW_BATTLE_TEST_CONDITION_HPP
