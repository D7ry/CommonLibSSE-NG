#include "RE/C/CombatBehaviorContextMagic.h"

namespace RE
{
	CombatBehaviorContextMagic::CombatBehaviorContextMagic(CombatInventoryItemMagic* citem)
	{
		using func_t = CombatBehaviorContextMagic*(CombatBehaviorContextMagic*, CombatInventoryItemMagic*);
		REL::Relocation<func_t> func{ RELOCATION_ID(48035, 0) };  
		func(this, citem);
	}

	float CombatBehaviorContextMagic::CalcCastMagicChance() const
	{
		using func_t = decltype(&CombatBehaviorContextMagic::CalcCastMagicChance);
		REL::Relocation<func_t> func{ RELOCATION_ID(48047, 0) };  
		return func(this);
	}

	float CombatBehaviorContextMagic::CalcDualCastMagicChance() const
	{
		using func_t = decltype(&CombatBehaviorContextMagic::CalcDualCastMagicChance);
		REL::Relocation<func_t> func{ RELOCATION_ID(48048, 0) };  
		return func(this);
	}

	MagicSystem::CastingType CombatBehaviorContextMagic::GetCastingType()
	{
		using func_t = decltype(&CombatBehaviorContextMagic::GetCastingType);
		REL::Relocation<func_t> func{ RELOCATION_ID(530050, 0) };  
		return func(this);
	}
}
