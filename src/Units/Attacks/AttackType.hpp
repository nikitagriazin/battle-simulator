//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_ATTACK_TYPE_HPP
#define SW_BATTLE_TEST_ATTACK_TYPE_HPP

#include "Core/Actor.hpp"
#include "Core/Condition.hpp"
#include "Core/OwnedBy.hpp"
#include "Units/Components/StatsComponent.hpp"
#include "Units/StatType.hpp"

#include <memory>

class AttackType : public OwnedBy
{
protected:
	StatType basedStat;
	std::shared_ptr<Condition> condition;
	std::shared_ptr<StatsComponent> statsComponent;

public:
	AttackType(std::shared_ptr<Actor>& owner, StatType stat, std::shared_ptr<Condition> cond) :
			basedStat(stat),
			condition(std::move(cond))
	{
		SetOwner(owner);
		statsComponent = GetOwner()->GetComponent<StatsComponent>();
	}

	virtual ~AttackType() = default;

	virtual int Damage()
	{
		return static_cast<int>(statsComponent->GetStat(basedStat));
	}

	[[nodiscard]]
	inline bool CanAttack(const std::shared_ptr<Actor>& target) const
	{
		return condition->isPassed(target);
	}
};

#endif	//SW_BATTLE_TEST_ATTACK_TYPE_HPP
