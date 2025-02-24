//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_CLOSE_STRENGTH_ATTACK_HPP
#define SW_BATTLE_TEST_CLOSE_STRENGTH_ATTACK_HPP

#include "Condition/InAttackRangeCondition.hpp"
#include "AttackType.hpp"

class CloseStrengthAttack : public AttackType
{
public:
	explicit CloseStrengthAttack(std::shared_ptr<Actor>& owner, std::shared_ptr<InAttackRangeCondition> cond) :
			AttackType(owner, StatType::Strength, std::move(cond))
	{}
};

#endif	//SW_BATTLE_TEST_CLOSE_STRENGTH_ATTACK_HPP
