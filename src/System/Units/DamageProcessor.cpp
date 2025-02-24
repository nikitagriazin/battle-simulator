//
// Created by NikitaGriazin on 20.02.2025.
//

#include "DamageProcessor.hpp"

#include "Utility/ServiceDefines.hpp"

DamageProcessor::DamageProcessor() :
		events()
{}

void DamageProcessor::RegisterDamage(const DamageEvent& event)
{
	events.push(event);
}

void DamageProcessor::ApplyDamage()
{
	while (!events.empty())
	{
		auto event = events.front();
		auto target = events.front().target.lock();
		auto targetHealthComponent = target->GetComponent<HealthComponent>();
		uint32_t uDamage
			= (event.damage < 0)
				  ? 0
				  : static_cast<uint32_t>(
						event
							.damage);  // if damage < then it was heal for this need another io event, so here it's not matter
		ServiceLocator::GetInstance().Resolve<SimulationLog>()->log(
			sw::io::UnitAttacked{
				event.attacker.lock()->GetId(), target->GetId(), uDamage, targetHealthComponent->GetCurrentHP()});
		targetHealthComponent->ApplyDamage(event.damage);
		events.pop();
	}
}
