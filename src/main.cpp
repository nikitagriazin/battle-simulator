#include "IO/System/PrintDebug.hpp"
#include "System/Simulation.hpp"
#include "Utility/ServiceDefines.hpp"
#include "Utility/ServiceLocator.hpp"

#include <IO/Commands/CreateMap.hpp>
#include <IO/Commands/March.hpp>
#include <IO/Commands/SpawnHunter.hpp>
#include <IO/Commands/SpawnSwordsman.hpp>
#include <IO/System/CommandParser.hpp>
#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
	using namespace sw;
	RegisterServices();

	if (argc != 2)
	{
		throw std::runtime_error("Error: No file specified in command line argument");
	}

	std::ifstream file(argv[1]);
	if (!file)
	{
		throw std::runtime_error("Error: File not found - " + std::string(argv[1]));
	}

	auto commandQueue = ServiceLocator::GetInstance().Resolve<GameCommandQueue>();
	auto simulation = ServiceLocator::GetInstance().Resolve<Simulation>();

	std::cout << "Commands:\n";

	io::CommandParser parser;
	parser
		.add<io::CreateMap>(
			[&](auto command)
			{
				sw::printDebug(std::cout, command);
				commandQueue->PushCommand(command);
			})
		.add<io::SpawnSwordsman>(
			[&](auto command)
			{
				sw::printDebug(std::cout, command);
				commandQueue->PushCommand(command);
			})
		.add<io::SpawnHunter>(
			[&](auto command)
			{
				sw::printDebug(std::cout, command);
				commandQueue->PushCommand(command);
			})
		.add<io::March>(
			[&](auto command)
			{
				sw::printDebug(std::cout, command);
				commandQueue->PushCommand(command);
			});

	parser.parse(file);

	std::cout << "\n\nEvents:\n";

	simulation->Run();

	return 0;
}
