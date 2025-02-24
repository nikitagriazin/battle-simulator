//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_BEHAVIOUR_LOGIC_COMPONENT_HPP
#define SW_BATTLE_TEST_BEHAVIOUR_LOGIC_COMPONENT_HPP

#include "Core/ActorComponent.hpp"
#include "HealthComponent.hpp"
#include "Units/Behaviours/Behaviour.hpp"

#include <map>

class BehaviourLogicComponent : public ActorComponent
{
private:
	std::shared_ptr<Behaviour> currentBehavior;
	std::map<int, std::shared_ptr<Behaviour>, std::greater<>> behaviorPriorities;
	bool isNoAvailableActions;
	std::shared_ptr<HealthComponent> healthComponent;
public:
	BehaviourLogicComponent();

	void AddBehavior(const std::shared_ptr<Behaviour>& behaviour, int priority);
	void Activate() override;
	void Tick(uint32_t tick) override;

	inline void SetIsNoAvailableActions(bool _isNoAvailableActions)
	{
		isNoAvailableActions = _isNoAvailableActions;
	}

	[[nodiscard]]
	inline bool IsNoAvailableActions()
	{
		return isNoAvailableActions;
	}
};

#endif	//SW_BATTLE_TEST_BEHAVIOUR_LOGIC_COMPONENT_HPP
