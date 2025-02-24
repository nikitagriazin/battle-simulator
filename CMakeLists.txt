cmake_minimum_required(VERSION 3.27)
project(sw_battle_test)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
add_executable(sw_battle_test ${SOURCES} src/Core/ActorComponent.hpp src/Core/Actor.hpp src/Units/Behaviours/Behaviour.hpp src/Core/OwnedBy.hpp src/System/Map.cpp src/System/Map.hpp
        src/Utility/Vector2.hpp
        src/Utility/ServiceLocator.hpp
        src/Units/Components/BehaviourLogicComponent.cpp
        src/Units/Components/BehaviourLogicComponent.hpp
        src/Core/Condition.hpp
        src/Units/Components/HealthComponent.cpp
        src/Units/Components/HealthComponent.hpp
        src/Units/Components/StatsComponent.cpp
        src/Units/Components/StatsComponent.hpp
        src/Units/Components/PositionComponent.cpp
        src/Units/Components/PositionComponent.hpp
        src/Units/Components/AttackComponent.cpp
        src/Units/Components/AttackComponent.hpp
        src/Units/Attacks/AttackType.hpp
        src/Units/StatType.hpp
        src/Units/Attacks/RangeAgilityAttack.hpp
        src/Units/Attacks/CloseStrengthAttack.hpp
        src/Condition/InAttackRangeCondition.hpp
        src/Condition/AlwaysTrueCondition.hpp
        src/System/MapDefines.hpp
        src/System/Simulation.cpp
        src/System/Simulation.hpp
        src/Core/GameObject.hpp
        src/System/Units/UnitFactory.cpp
        src/System/Units/UnitFactory.hpp
        src/Units/Behaviours/MoveAndAttackBehaviour.hpp
        src/System/Units/DamageProcessor.cpp
        src/System/Units/DamageProcessor.hpp
        src/System/GameState.cpp
        src/System/GameState.hpp
        src/System/SimulationLog.hpp
        src/Utility/ServiceDefines.hpp
        src/System/Units/UnitRegistry.cpp
        src/System/Units/UnitRegistry.hpp
        src/System/Mediator/GameCommandMediator.cpp
        src/System/Mediator/GameCommandMediator.hpp
        src/System/Mediator/CommandHandler.hpp
        src/System/Mediator/CreateMapHandler.cpp
        src/System/Mediator/CreateMapHandler.hpp
        src/System/Mediator/SpawnSwordsmanHandler.cpp
        src/System/Mediator/SpawnSwordsmanHandler.hpp
        src/System/Mediator/SpawnHunterHandler.cpp
        src/System/Mediator/SpawnHunterHandler.hpp
        src/System/Mediator/UnitMarchHandler.cpp
        src/System/Mediator/UnitMarchHandler.hpp
        src/System/Mediator/GameCommandQueue.cpp
        src/System/Mediator/GameCommandQueue.hpp
)

target_include_directories(sw_battle_test PUBLIC src/)
