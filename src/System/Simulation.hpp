//
// Created by NikitaGriazin on 14.02.2025.
//

#ifndef SW_BATTLE_TEST_SIMULATION_HPP
#define SW_BATTLE_TEST_SIMULATION_HPP

#include "Core/GameObject.hpp"
#include "GameState.hpp"
#include "System/Mediator/GameCommandQueue.hpp"
#include "System/Units/DamageProcessor.hpp"
#include "System/Units/UnitRegistry.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

class Simulation
{
private:
	std::shared_ptr<GameState> gameState;
	std::shared_ptr<DamageProcessor> damageController;
	std::shared_ptr<UnitRegistry> unitRegistry;
	std::shared_ptr<GameCommandQueue> commandQueue;
	std::unordered_map<uint32_t, std::shared_ptr<GameObject>> objects;

public:
	explicit Simulation(
		std::shared_ptr<GameState>& gameState,
		std::shared_ptr<DamageProcessor>& damageController,
		std::shared_ptr<UnitRegistry>& unitRegistry,
		std::shared_ptr<GameCommandQueue>& commandQueue);

	void AddObject(uint32_t key, const std::shared_ptr<GameObject>& obj);

	bool IsIdRegistered(uint32_t key);

	void Run();

	template <typename T>
	std::shared_ptr<T> GetObjectAs(uint32_t id)
	{
		static_assert(std::is_base_of_v<GameObject, T>, "T must be derived from GameObject");
		return std::dynamic_pointer_cast<T>(objects.at(id));
	}

private:
	void Activate();
	void Process();
	void Deactivate();
	void Terminate();
};

#endif	//SW_BATTLE_TEST_SIMULATION_HPP
