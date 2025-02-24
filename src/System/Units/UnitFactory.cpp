//
// Created by NikitaGriazin on 20.02.2025.
//

#include "UnitFactory.hpp"

#include "Condition/AlwaysTrueCondition.hpp"
#include "Units/Attacks/CloseStrengthAttack.hpp"
#include "Units/Attacks/RangeAgilityAttack.hpp"
#include "Units/Behaviours/MoveAndAttackBehaviour.hpp"
#include "Units/Components/AttackComponent.hpp"
#include "Units/Components/BehaviourLogicComponent.hpp"
#include "Units/Components/HealthComponent.hpp"
#include "Units/Components/PositionComponent.hpp"
#include "Units/Components/StatsComponent.hpp"

std::shared_ptr<Actor> UnitFactory::SpawnSwordsman(uint32_t unitId, Vector2 position, uint32_t hp, uint32_t strength)
{
	auto actor = std::make_shared<Actor>(unitId);
	auto stats = std::make_shared<StatsComponent>();
	stats->SetStat(StatType::Strength, strength);
	actor->AddComponent(stats);

	auto health = std::make_shared<HealthComponent>(hp);
	actor->AddComponent(health);

	auto behaviourLogic = std::make_shared<BehaviourLogicComponent>();
	actor->AddComponent(behaviourLogic);
	auto bhvCond = std::make_shared<AlwaysTrueCondition>();
	auto moveAndAttackBhv = std::make_shared<MoveAndAttackBehaviour>(bhvCond);
	behaviourLogic->AddBehavior(moveAndAttackBhv, 1);

	auto attack = std::make_shared<AttackComponent>();
	auto attackCloseType = std::make_shared<CloseStrengthAttack>(std::make_shared<InAttackRangeCondition>(0, 1, actor));
	attack->AddAttack(attackCloseType);
	actor->AddComponent(attack);

	auto positionComponent = std::make_shared<PositionComponent>(true, position);
	actor->AddComponent(positionComponent);
	return actor;
}

std::shared_ptr<Actor> UnitFactory::SpawnHunter(
	uint32_t unitId, Vector2 position, uint32_t hp, uint32_t agility, uint32_t strength, uint32_t range)
{
	auto actor = std::make_shared<Actor>(unitId);
	auto stats = std::make_shared<StatsComponent>();
	stats->SetStat(StatType::Strength, strength);
	stats->SetStat(StatType::Agility, agility);
	stats->SetStat(StatType::Range, range);
	actor->AddComponent(stats);

	auto health = std::make_shared<HealthComponent>(hp);
	actor->AddComponent(health);

	auto behaviourLogic = std::make_shared<BehaviourLogicComponent>();
	actor->AddComponent(behaviourLogic);
	auto bhvCond = std::make_shared<AlwaysTrueCondition>();
	auto moveAndAttackBhv = std::make_shared<MoveAndAttackBehaviour>(bhvCond);
	behaviourLogic->AddBehavior(moveAndAttackBhv, 1);

	auto attack = std::make_shared<AttackComponent>();
	auto attackCloseType = std::make_shared<CloseStrengthAttack>(std::make_shared<InAttackRangeCondition>(0, 1, actor));
	auto attackRangeType = std::make_shared<RangeAgilityAttack>(std::make_shared<InAttackRangeCondition>(1, range, actor));
	attack->AddAttack(attackCloseType);
	attack->AddAttack(attackRangeType);
	actor->AddComponent(attack);

	auto positionComponent = std::make_shared<PositionComponent>(true, position);
	actor->AddComponent(positionComponent);
	return actor;
}
