//
// Created by GreatShogun on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_GAMECOMMANDQUEUE_HPP
#define SW_BATTLE_TEST_GAMECOMMANDQUEUE_HPP

#include "GameCommandMediator.hpp"

#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <variant>

class GameCommandQueue
{
private:
	using CommandVariant = std::variant<sw::io::CreateMap, sw::io::SpawnSwordsman, sw::io::SpawnHunter, sw::io::March>;

	std::queue<CommandVariant> commandQueue;
	std::mutex queueMutex;
	std::shared_ptr<GameCommandMediator> mediator;

public:
	explicit GameCommandQueue(std::shared_ptr<GameCommandMediator>& mediator);
	void PushCommand(CommandVariant command);
	void ProcessCommands();
};

#endif	//SW_BATTLE_TEST_GAMECOMMANDQUEUE_HPP
