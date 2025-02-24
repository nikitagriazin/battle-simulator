//
// Created by NikitaGriazin on 26.01.2025.
//

#ifndef CPP_BATTLE_TEST_SERVER_OWNED_BY_HPP
#define CPP_BATTLE_TEST_SERVER_OWNED_BY_HPP

#include <iostream>
#include <memory>
#include <vector>

class Actor;

class OwnedBy
{
protected:
	std::shared_ptr<Actor> owner;

public:
	virtual ~OwnedBy() = default;
	[[nodiscard]]
	std::shared_ptr<Actor> GetOwner() const
	{
		return owner;
	}

protected:
	inline void SetOwner(const std::shared_ptr<Actor>& newOwner)
	{
		if (owner == nullptr)
		{
			owner = newOwner;
		}
		else
		{
			std::cerr << "Error: Owner can only be set once.\n";
		}
	}
};

#endif	//CPP_BATTLE_TEST_SERVER_OWNED_BY_HPP
