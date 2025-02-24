//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_VECTOR2_HPP
#define SW_BATTLE_TEST_VECTOR2_HPP

#include <cstdint>
#include <ostream>
#include <valarray>

class Vector2
{
public:
	uint32_t x, y;

	Vector2(uint32_t x = 0, uint32_t y = 0) :
			x(x),
			y(y)
	{}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	void Set(uint32_t new_x, uint32_t new_y)
	{
		x = new_x;
		y = new_y;
	}

	inline static uint32_t DistanceSquared(const Vector2& a, const Vector2& b)
	{
		int dx = static_cast<int>(b.x) - static_cast<int>(a.x);
		int dy = static_cast<int>(b.y) - static_cast<int>(a.y);
		return dx * dx + dy * dy;
	}

	inline static double Distance(const Vector2& a, const Vector2& b)
	{
		return std::sqrt(DistanceSquared(a, b));
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vec)
	{
		os << "(" << vec.x << ", " << vec.y << ")";
		return os;
	}
};

namespace std {
	template <>
	struct hash<Vector2>
	{
		size_t operator()(const Vector2& v) const noexcept
		{
			return std::hash<uint32_t>{}(v.x) ^ (std::hash<uint32_t>{}(v.y) << 1);
		}
	};
}

#endif	//SW_BATTLE_TEST_VECTOR2_HPP
