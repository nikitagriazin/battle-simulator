//
// Created by NikitaGriazin on 26.01.2025.
//

#ifndef CPP_BATTLE_TEST_SERVER_ACTOR_COMPONENT_HPP
#define CPP_BATTLE_TEST_SERVER_ACTOR_COMPONENT_HPP

#include "OwnedBy.hpp"

class ActorComponent : public OwnedBy
{
	friend class Actor;

public:
	virtual ~ActorComponent() = default;

	virtual void Initialize() {}

	virtual void Tick(uint32_t tick) {}

	virtual void Activate() {}

	virtual void Deactivate() {}

	virtual void Terminate() {}
};

#endif	//CPP_BATTLE_TEST_SERVER_ACTOR_COMPONENT_HPP
