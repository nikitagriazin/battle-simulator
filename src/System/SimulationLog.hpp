//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_SIMULATION_LOG_HPP
#define SW_BATTLE_TEST_SIMULATION_LOG_HPP

#include "GameState.hpp"
#include "IO/System/EventLog.hpp"

#include <IO/Events/MapCreated.hpp>
#include <IO/Events/MarchEnded.hpp>
#include <IO/Events/MarchStarted.hpp>
#include <IO/Events/UnitAttacked.hpp>
#include <IO/Events/UnitDied.hpp>
#include <IO/Events/UnitMoved.hpp>
#include <IO/Events/UnitSpawned.hpp>

#include <memory>
#include <utility>

class SimulationLog
{
private:
	std::shared_ptr<sw::EventLog> eventLog;
	std::shared_ptr<GameState> gameState;

public:
	SimulationLog(std::shared_ptr<sw::EventLog>& eventLog, std::shared_ptr<GameState>& gameState) :
			eventLog(eventLog),
			gameState(gameState)
	{}

	void Initialize() {

	}

	template <class TEvent>
	void log(TEvent&& event)
	{
		eventLog->log(gameState->GetTick(), std::forward<std::remove_reference_t<TEvent>>(event));
	}
};

#endif	//SW_BATTLE_TEST_SIMULATION_LOG_HPP

