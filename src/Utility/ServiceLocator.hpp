//
// Created by NikitaGriazin on 02.02.2025.
//

#ifndef SW_BATTLE_TEST_SIMPLE_IOC_CONTAINER_HPP
#define SW_BATTLE_TEST_SIMPLE_IOC_CONTAINER_HPP

#include <functional>
#include <memory>
#include <optional>
#include <typeindex>
#include <unordered_map>

class ServiceLocator
{
private:
	std::unordered_map<std::type_index, std::function<std::shared_ptr<void>()>> factories;
	std::unordered_map<std::type_index, std::shared_ptr<void>> instances;

	ServiceLocator() = default;

public:
	static ServiceLocator& GetInstance()
	{
		static ServiceLocator instance;
		return instance;
	}

	ServiceLocator(const ServiceLocator&) = delete;
	ServiceLocator& operator=(const ServiceLocator&) = delete;
	ServiceLocator(ServiceLocator&&) = delete;
	ServiceLocator& operator=(ServiceLocator&&) = delete;

	template <typename T, typename... Args>
	void RegisterType(Args&&... args) {
		factories[typeid(T)] = [args...]() -> std::shared_ptr<void> {
			return std::make_shared<T>(std::forward<Args>(args)...);
		};
	}

	template <typename T>
	void RegisterInstance(std::shared_ptr<T> instance)
	{
		instances[typeid(T)] = instance;
	}

	template <typename T>
	std::shared_ptr<T> Resolve() {
		auto it = instances.find(typeid(T));
		if (it != instances.end()) {
			return std::static_pointer_cast<T>(it->second);
		}

		auto fit = factories.find(typeid(T));
		if (fit == factories.end()) {
			throw std::runtime_error("Dependency not registered: " + std::string(typeid(T).name()));
		}

		auto instance = std::static_pointer_cast<T>(fit->second());
		instances[typeid(T)] = instance;
		return instance;
	}
};

#endif	//SW_BATTLE_TEST_SIMPLE_IOC_CONTAINER_HPP
