//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_IN_ATTACK_RANGE_CONDITION_HPP
#define SW_BATTLE_TEST_IN_ATTACK_RANGE_CONDITION_HPP

#include "Core/Actor.hpp"
#include "Core/Condition.hpp"
#include "Units/Components/PositionComponent.hpp"

#include <memory>
#include <utility>

class InAttackRangeCondition : public Condition
{
private:
	uint32_t minSquared;
	uint32_t maxSquared;
	std::shared_ptr<Actor> owner;

public:
	explicit InAttackRangeCondition(uint32_t min, uint32_t max, std::shared_ptr<Actor>& owner) :
			minSquared(min*min),
			maxSquared(max*max),
			owner(owner)
	{}

	[[nodiscard]]
	inline bool isPassed(const std::any& argument) const override
	{
		if (!argument.has_value() || argument.type() != typeid(std::shared_ptr<Actor>))
		{
			return false;
		}

		auto otherActor = std::any_cast<std::shared_ptr<Actor>>(argument);

		auto ownerPosition = owner->GetComponent<PositionComponent>();
		auto otherActorPosition = otherActor->GetComponent<PositionComponent>();

		auto distanceBetweenActors = Vector2::DistanceSquared(ownerPosition->GetPosition(), otherActorPosition->GetPosition());

		return distanceBetweenActors >= minSquared && distanceBetweenActors <= maxSquared;
	}
};

#endif	//SW_BATTLE_TEST_IN_ATTACK_RANGE_CONDITION_HPP
