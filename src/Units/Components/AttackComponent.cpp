//
// Created by NikitaGriazin on 02.02.2025.
//

#include "AttackComponent.hpp"

void AttackComponent::AddAttack(const std::shared_ptr<AttackType>& attack)
{
	if (attack == nullptr) {
		return;
	}

	attacks.push_back(attack);
}

std::pair<int, std::shared_ptr<AttackType>> AttackComponent::ChooseMostPowerfulAttack(const std::shared_ptr<Actor>& target)
{
	std::pair<int, std::shared_ptr<AttackType>> mostPowerfulAttack(0, nullptr);
	for (const auto& attack : attacks)
	{
		if (!attack->CanAttack(target))
		{
			continue;
		}

		auto damage = attack->Damage();
		if (damage > mostPowerfulAttack.first)
		{
			mostPowerfulAttack.first = damage;
			mostPowerfulAttack.second = attack;
		}
	}
	return mostPowerfulAttack;
}
