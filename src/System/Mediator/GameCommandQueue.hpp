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
	explicit GameCommandQueue(std::shared_ptr<GameCommandMediator>& mediator) :
			mediator(mediator)
	{}

	void PushCommand(CommandVariant command)
	{
		std::lock_guard<std::mutex> lock(queueMutex);
		commandQueue.push(command);
	}

	void ProcessCommands()
	{
		std::queue<CommandVariant> commands;
		{
			std::lock_guard<std::mutex> lock(queueMutex);
			std::swap(commands, commandQueue);
		}

		while (!commands.empty())
		{
			std::visit(
				[this](auto&& cmd)
				{
					using T = std::decay_t<decltype(cmd)>;
					if constexpr (std::is_same_v<T, sw::io::CreateMap>)
					{
						mediator->ProcessCreateMapCommand(cmd);
					}
					else if constexpr (std::is_same_v<T, sw::io::SpawnSwordsman>)
					{
						mediator->ProcessSpawnSwordsmanCommand(cmd);
					}
					else if constexpr (std::is_same_v<T, sw::io::SpawnHunter>)
					{
						mediator->ProcessSpawnHunterCommand(cmd);
					}
					else if constexpr (std::is_same_v<T, sw::io::March>)
					{
						mediator->ProcessMarchCommand(cmd);
					}
				},
				commands.front());
			commands.pop();
		}
	}
};

#endif	//SW_BATTLE_TEST_GAMECOMMANDQUEUE_HPP
