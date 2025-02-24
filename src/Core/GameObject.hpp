//
// Created by NikitaGriazin on 14.02.2025.
//

#ifndef SW_BATTLE_TEST_GAME_OBJECT_HPP
#define SW_BATTLE_TEST_GAME_OBJECT_HPP

#include <cstdint>

class GameObject {
public:
	uint32_t id;
	explicit GameObject(uint32_t id) : id(id) {}
	virtual ~GameObject() = default;

	virtual void Initialize() = 0;
	virtual void Activate() = 0;
	virtual void Tick(uint32_t tick) = 0;
	virtual void Deactivate() = 0;
	virtual void Terminate() = 0;
};

#endif	//SW_BATTLE_TEST_GAME_OBJECT_HPP
