//
// Created by NikitaGriazin on 02.02.2025.
//

#include "PositionComponent.hpp"

#include "Utility/ServiceDefines.hpp"

#include <stack>

struct AStarNode
{
	Vector2 position;
	float fCost;

	AStarNode(Vector2 pos, float cost) :
			position(pos),
			fCost(cost)
	{}

	bool operator<(const AStarNode& other) const
	{
		return fCost > other.fCost;
	}
};

struct CompareNodes
{
	bool operator()(const AStarNode& a, const AStarNode& b) const
	{
		return a.fCost > b.fCost;
	}
};

PositionComponent::PositionComponent(bool isOccupiesSlot, Vector2 position) :
		occupiesSlot(isOccupiesSlot),
		currentPosition(position),
		targetPosition(position)
{
	map = ServiceLocator::GetInstance().Resolve<Map>();
}

void PositionComponent::MarchTo(Vector2 position)
{
	if (position == currentPosition)
	{
		return;
	}

	if (position != currentPosition)
	{
		targetPosition = position;
	}
	ServiceLocator::GetInstance().Resolve<SimulationLog>()->log(
		sw::io::MarchStarted{GetOwner()->GetId(), currentPosition.x, currentPosition.y, targetPosition.x, targetPosition.y});
	BuildPath();
}

void PositionComponent::MoveToNextPosition()
{
	if (targetPosition == currentPosition)
	{
		return;
	}

	if (path.empty())
	{
		BuildPath();
	}

	if (path.empty())
	{
		return;
	}

	auto nextPosition = path.front();
	if (map->IsCellOccupied(nextPosition))
	{
		BuildPath();
		if (path.empty())
			return;
		nextPosition = path.front();
	}

	if (occupiesSlot)
	{
		map->FreeCell(currentPosition);
		map->OccupyCell(nextPosition, UNIT_SYMBOL);
	}

	currentPosition = nextPosition;
	ServiceLocator::GetInstance().Resolve<SimulationLog>()->log(sw::io::UnitMoved{GetOwner()->GetId(), nextPosition.x, nextPosition.y});

	if (targetPosition == currentPosition)
	{
		ServiceLocator::GetInstance().Resolve<SimulationLog>()->log(
			sw::io::MarchEnded{GetOwner()->GetId(), currentPosition.x, currentPosition.y});
	}
}

void PositionComponent::BuildPath()
{
	path = {};
	if (!map->IsWithinBounds(targetPosition) || map->IsCellOccupied(targetPosition))
	{
		return;
	}

	std::priority_queue<AStarNode, std::vector<AStarNode>, CompareNodes> openSet;
	std::unordered_map<Vector2, Vector2> cameFrom;
	std::unordered_map<Vector2, uint32_t> gScore;
	std::unordered_map<Vector2, uint32_t> fScore;

	auto heuristic = [](const Vector2& a, const Vector2& b) -> uint32_t
	{
		return std::max(
			std::abs(static_cast<int32_t>(a.x) - static_cast<int32_t>(b.x)),
			std::abs(static_cast<int32_t>(a.y) - static_cast<int32_t>(b.y)));
	};

	gScore[currentPosition] = 0;
	fScore[currentPosition] = heuristic(currentPosition, targetPosition);
	openSet.emplace(currentPosition, fScore[currentPosition]);

	std::vector<std::pair<int, int>> directions
		= {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

	while (!openSet.empty())
	{
		Vector2 current = openSet.top().position;
		openSet.pop();

		if (current == targetPosition)
		{
			std::stack<Vector2> stack;
			Vector2 step = targetPosition;

			while (cameFrom.find(step) != cameFrom.end())
			{
				stack.push(step);
				step = cameFrom[step];
			}

			while (!stack.empty()) {
				path.push(stack.top());
				stack.pop();
			}

			return;
		}

		for (const auto& dir : directions)
		{
			if (current.x == 0 && dir.first == -1 || current.y == 0 && dir.second == -1)
			{
				continue;
			}

			Vector2 neighbor = {current.x + dir.first, current.y + dir.second};

			if (!map->IsWithinBounds(neighbor) || map->IsCellOccupied(neighbor))
			{
				continue;
			}

			uint32_t tentativeGScore = gScore[current] + 1;

			if (!gScore.count(neighbor) || tentativeGScore < gScore[neighbor])
			{
				cameFrom[neighbor] = current;
				gScore[neighbor] = tentativeGScore;
				fScore[neighbor] = tentativeGScore + heuristic(neighbor, targetPosition);
				openSet.emplace(neighbor, fScore[neighbor]);
			}
		}
	}
}
