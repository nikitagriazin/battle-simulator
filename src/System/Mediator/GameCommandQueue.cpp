//
// Created by GreatShogun on 24.02.2025.
//

#include "GameCommandQueue.hpp"

explicit GameCommandQueue::GameCommandQueue(std::shared_ptr<GameCommandMediator>& mediator) :
		mediator(mediator)
{}

void GameCommandQueue::PushCommand(CommandVariant command)
{
	std::lock_guard<std::mutex> lock(queueMutex);
	commandQueue.push(command);
}

void GameCommandQueue::ProcessCommands()
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