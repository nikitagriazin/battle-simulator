//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_MOVEMENT_COMPONENT_HPP
#define SW_BATTLE_TEST_MOVEMENT_COMPONENT_HPP

#include "Core/ActorComponent.hpp"
#include "IO/Events/MapCreated.hpp"
#include "IO/Events/UnitMoved.hpp"
#include "IO/System/EventLog.hpp"
#include "System/Map.hpp"
#include "Utility/ServiceLocator.hpp"
#include "Utility/Vector2.hpp"

#include <queue>

class PositionComponent : public ActorComponent
{
private:
	Vector2 currentPosition;
	Vector2 targetPosition;
	bool occupiesSlot;
	std::shared_ptr<Map> map;
	std::queue<Vector2> path;

public:
	PositionComponent(bool isOccupiesSlot, Vector2 position);

	inline void SetPosition(Vector2 newPosition)
	{
		currentPosition = newPosition;
	}

	[[nodiscard]]
	inline Vector2 GetPosition()
	{
		return currentPosition;
	}

	[[nodiscard]]
	inline Vector2 GetTargetPosition()
	{
		return targetPosition;
	}

	[[nodiscard]]
	inline bool IsTargetAchieved()
	{
		return currentPosition == targetPosition;
	}

	[[nodiscard]]
	inline bool IsOccupiesSlot() const
	{
		return occupiesSlot;
	}

	void MarchTo(Vector2 position);
	void MoveToNextPosition();

private:
	void BuildPath();
};

#endif	//SW_BATTLE_TEST_MOVEMENT_COMPONENT_HPP
