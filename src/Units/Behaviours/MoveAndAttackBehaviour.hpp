//
// Created by NikitaGriazin on 20.02.2025.
//

#ifndef SW_BATTLE_TEST_MOVE_AND_ATTACK_BEHAVIOUR_HPP
#define SW_BATTLE_TEST_MOVE_AND_ATTACK_BEHAVIOUR_HPP

#include "Behaviour.hpp"
#include "System/Units/DamageProcessor.hpp"
#include "System/Units/UnitRegistry.hpp"
#include "Units/Components/AttackComponent.hpp"
#include "Units/Components/BehaviourLogicComponent.hpp"
#include "Units/Components/PositionComponent.hpp"

class MoveAndAttackBehaviour : public Behaviour
{
private:
	std::shared_ptr<DamageProcessor> damageController;
	std::shared_ptr<UnitRegistry> unitRegistry;
	std::shared_ptr<AttackComponent> attackComponent;
	std::shared_ptr<PositionComponent> positionComponent;
	std::shared_ptr<BehaviourLogicComponent> logicComponent;

public:
	explicit MoveAndAttackBehaviour(std::shared_ptr<Condition> cond) :
			Behaviour(std::move(cond))
	{}

	void Initialize() override {
		damageController = ServiceLocator::GetInstance().Resolve<DamageProcessor>();
		unitRegistry = ServiceLocator::GetInstance().Resolve<UnitRegistry>();
		attackComponent = owner->GetComponent<AttackComponent>();
		positionComponent = owner->GetComponent<PositionComponent>();
		logicComponent = owner->GetComponent<BehaviourLogicComponent>();
	}

	void Tick(uint32_t Tick) override
	{
		auto owner = GetOwner();

		auto targets = unitRegistry->GetPossibleTargets(owner);
		std::pair<int, std::shared_ptr<AttackType>> attack{0, nullptr};
		for (auto &target : targets) {
			attack = attackComponent->ChooseMostPowerfulAttack(target);
			if (attack.second != nullptr) {
				damageController->RegisterDamage({owner, target, attack.first});
				return;
			}
		}

		if (!positionComponent->IsTargetAchieved()) {
			positionComponent->MoveToNextPosition();
		} else {
			logicComponent->SetIsNoAvailableActions(true);
		}
	}
};

#endif	//SW_BATTLE_TEST_MOVE_AND_ATTACK_BEHAVIOUR_HPP
