//
// Created by NikitaGriazin on 26.01.2025.
//

#ifndef CPP_BATTLE_TEST_SERVER_PAWN_HPP
#define CPP_BATTLE_TEST_SERVER_PAWN_HPP

#include "ActorComponent.hpp"
#include "GameObject.hpp"

#include <memory>
#include <typeindex>
#include <unordered_map>

class Actor : public std::enable_shared_from_this<Actor>, public GameObject
{
private:
	std::unordered_map<std::type_index, std::shared_ptr<ActorComponent>> components;
	bool active = true;

public:
	explicit Actor(uint32_t id) :
			GameObject(id)
	{}

	virtual ~Actor() = default;

	void Initialize() override
	{
		for (auto& [_, component] : components)
		{
			component->Initialize();
		}
	}

	void Activate() override
	{
		active = true;
		for (auto& [_, component] : components)
		{
			component->Activate();
		}
	}

	void Tick(uint32_t tick) override
	{
		if (!active)
		{
			return;
		}

		for (auto& [_, component] : components)
		{
			component->Tick(tick);
		}
	}

	void Deactivate() override
	{
		active = false;
		for (auto& [_, component] : components)
		{
			component->Deactivate();
		}
	}

	void Terminate() override
	{
		for (auto& [_, component] : components)
		{
			component->Terminate();
		}
		components.clear();
	}

	template <typename T>
	std::shared_ptr<T> GetComponent()
	{
		auto it = components.find(typeid(T));
		if (it != components.end())
		{
			return std::dynamic_pointer_cast<T>(it->second);
		}
		return nullptr;
	}

	void AddComponent(const std::shared_ptr<ActorComponent>& component)
	{
		const std::type_index typeIndex = typeid(*component);
		components[typeIndex] = component;
		component->SetOwner(shared_from_this());
	}

	uint32_t GetId()
	{
		return id;
	}
};

#endif	//CPP_BATTLE_TEST_SERVER_PAWN_HPP
