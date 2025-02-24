//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_RANGE_AGILITY_ATTACK_HPP
#define SW_BATTLE_TEST_RANGE_AGILITY_ATTACK_HPP

#include "AttackType.hpp"
#include "Condition/InAttackRangeCondition.hpp"

class RangeAgilityAttack : public AttackType
{
public:
	explicit RangeAgilityAttack(std::shared_ptr<InAttackRangeCondition> cond) :
			AttackType(StatType::Agility, std::move(cond))
	{}
};

#endif	//SW_BATTLE_TEST_RANGE_AGILITY_ATTACK_HPP
