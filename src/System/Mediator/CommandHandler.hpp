//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_COMMAND_HANDLER_HPP
#define SW_BATTLE_TEST_COMMAND_HANDLER_HPP

template <typename T>
class CommandHandler
{
public:
	virtual void Handle(T& command) = 0;
	virtual ~CommandHandler() = default;
};

#endif	//SW_BATTLE_TEST_COMMAND_HANDLER_HPP
