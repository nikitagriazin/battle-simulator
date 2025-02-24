//
// Created by NikitaGriazin on 26.01.2025.
//

#ifndef CPP_BATTLE_TEST_SERVER_MAP_HPP
#define CPP_BATTLE_TEST_SERVER_MAP_HPP

#include "MapDefines.hpp"
#include "Utility/Vector2.hpp"

#include <cstdint>
#include <vector>

class Map
{
private:
	uint32_t width, height;
	std::vector<std::vector<char>> grid;
	bool isInited;
public:
	Map();
	void InitMap(uint32_t w, uint32_t h);
	void AddObstacle(uint32_t x, uint32_t y);
	[[nodiscard]]
	bool IsWithinBounds(const Vector2& pos) const;
	[[nodiscard]]
	bool IsCellOccupied(const Vector2& pos) const;
	void OccupyCell(const Vector2& pos, char symbol);
	void FreeCell(const Vector2& pos);
};

#endif	//CPP_BATTLE_TEST_SERVER_MAP_HPP
