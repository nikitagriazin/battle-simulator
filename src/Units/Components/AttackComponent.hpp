//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_ATTACK_COMPONENT_HPP
#define SW_BATTLE_TEST_ATTACK_COMPONENT_HPP

#include "Units/Attacks/AttackType.hpp"

#include <vector>

class AttackComponent : public ActorComponent
{
private:
	std::vector<std::shared_ptr<AttackType>> attacks;

public:
	void AddAttack(const std::shared_ptr<AttackType>& attack);
	std::pair<int, std::shared_ptr<AttackType>> ChooseMostPowerfulAttack(const std::shared_ptr<Actor>& target);
};

#endif	//SW_BATTLE_TEST_ATTACK_COMPONENT_HPP
