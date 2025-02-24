//
// Created by NikitaGriazin on 24.02.2025.
//
#ifndef SW_BATTLE_TEST_SERVICE_DEFINES_HPP
#define SW_BATTLE_TEST_SERVICE_DEFINES_HPP

#include "ServiceLocator.hpp"
#include "System/Map.hpp"
#include "System/Mediator/GameCommandMediator.hpp"
#include "System/Mediator/GameCommandQueue.hpp"
#include "System/Simulation.hpp"
#include "System/SimulationLog.hpp"
#include "System/Units/DamageProcessor.hpp"
#include "System/Units/UnitRegistry.hpp"

static void RegisterServices()
{
	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<sw::EventLog>());
	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<GameState>());

	auto gameState = ServiceLocator::GetInstance().Resolve<GameState>();
	auto eventLog = ServiceLocator::GetInstance().Resolve<sw::EventLog>();
	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<SimulationLog>(eventLog, gameState));

	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<Map>());

	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<UnitRegistry>());
	auto unitRegistry = ServiceLocator::GetInstance().Resolve<UnitRegistry>();

	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<GameCommandMediator>());
	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<DamageProcessor>());

	auto commandMediator = ServiceLocator::GetInstance().Resolve<GameCommandMediator>();
	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<GameCommandQueue>(commandMediator));
	auto commandQueue = ServiceLocator::GetInstance().Resolve<GameCommandQueue>();
	auto damageController = ServiceLocator::GetInstance().Resolve<DamageProcessor>();

	ServiceLocator::GetInstance().RegisterInstance(std::make_shared<Simulation>(gameState, damageController, unitRegistry, commandQueue));
}

#endif	//SW_BATTLE_TEST_SERVICE_DEFINES_HPP
