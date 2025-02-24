//
// Created by NikitaGriazin on 24.02.2025.
//

#ifndef SW_BATTLE_TEST_GAME_STATE_HPP
#define SW_BATTLE_TEST_GAME_STATE_HPP

#include <cstdint>

class GameState
{
	friend class Simulation;

public:
	explicit GameState();

	[[nodiscard]] inline bool GetIsActive() const
	{
		return isActive;
	}

	[[nodiscard]] inline uint32_t GetTick() const
	{
		return tick;
	}

private:
	bool isActive;
	uint32_t tick;

	void SetIsActive(bool active);
	void Tick();
};

#endif	//SW_BATTLE_TEST_GAME_STATE_HPP
