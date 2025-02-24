//
// Created by NikitaGriazin on 26.01.2025.
//

#include "Map.hpp"

#include "IO/Events/MapCreated.hpp"
#include "IO/System/EventLog.hpp"
#include "Utility/ServiceDefines.hpp"
#include "Utility/ServiceLocator.hpp"

Map::Map() :
		width(16),
		height(16),
		grid(width, std::vector<char>(height, EMPTY_CELL)),
		isInited(false)
{}

void Map::InitMap(uint32_t w, uint32_t h)
{
	width = w;
	height = h;
	grid.assign(h, std::vector<char>(w, EMPTY_CELL));
	ServiceLocator::GetInstance().Resolve<SimulationLog>()->log(sw::io::MapCreated{w, h});
	isInited = true;
}

void Map::AddObstacle(uint32_t x, uint32_t y)
{
	if (IsWithinBounds(Vector2(x, y)))
	{
		grid[y][x] = OBSTACLE_CELL;
	}
}

bool Map::IsWithinBounds(const Vector2& pos) const
{
	return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
}

bool Map::IsCellOccupied(const Vector2& pos) const
{
	return grid[pos.y][pos.x] != EMPTY_CELL;
}

void Map::OccupyCell(const Vector2& pos, char symbol)
{
	if (IsWithinBounds(pos))
	{
		grid[pos.y][pos.x] = symbol;
	}
}

void Map::FreeCell(const Vector2& pos)
{
	if (IsWithinBounds(pos))
	{
		grid[pos.y][pos.x] = EMPTY_CELL;
	}
}
