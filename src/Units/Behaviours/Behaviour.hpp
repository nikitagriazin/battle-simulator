//
// Created by NikitaGriazin on 26.01.2025.
//

#ifndef CPP_BATTLE_TEST_SERVER_BEHAVIOUR_HPP
#define CPP_BATTLE_TEST_SERVER_BEHAVIOUR_HPP

#include "Core/Actor.hpp"
#include "Core/Condition.hpp"
#include "Core/OwnedBy.hpp"

class Behaviour : public OwnedBy
{
	friend class BehaviourLogicComponent;

protected:
	std::shared_ptr<Condition> condition;

public:
	explicit Behaviour(std::shared_ptr<Condition> cond) :
			condition(std::move(cond))
	{}

	virtual ~Behaviour() = default;

	virtual void Initialize() {}

	virtual void Tick(uint32_t tick) {}

	virtual void Terminate() {}

	[[nodiscard]]
	inline bool CanRun() const
	{
		return condition->isPassed({});
	}
};

#endif	//CPP_BATTLE_TEST_SERVER_BEHAVIOUR_HPP
