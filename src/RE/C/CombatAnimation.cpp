#include "RE/C/CombatAnimation.h"

namespace RE
{
	CombatAnimation::CombatAnimation(Actor* actor, ANIM anim)
	{
		using func_t = CombatAnimation*(CombatAnimation*, Actor*, ANIM);
		REL::Relocation<func_t> func{ RELOCATION_ID(43235, 0) };  
		func(this, actor, anim);
	}

	CombatAnimation::CombatAnimation(Actor* actor, TESObjectREFR* target, ANIM anim)
	{
		using func_t = CombatAnimation*(CombatAnimation*, Actor*, TESObjectREFR*, ANIM);
		REL::Relocation<func_t> func{ RELOCATION_ID(43236, 0) };  
		func(this, actor, target, anim);
	}

	CombatAnimation::CombatAnimation(Actor* actor, BGSAction* action)
	{
		using func_t = CombatAnimation*(CombatAnimation*, Actor * actor, BGSAction*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43237, 0) };  
		func(this, actor, action);
	}

	bool CombatAnimation::Execute(Actor* actor, CombatAnimation::ANIM anim)
	{
		using func_t = bool(Actor*, CombatAnimation::ANIM);
		REL::Relocation<func_t> func{ RELOCATION_ID(43245, 0) };  
		return func(actor, anim);
	}

	bool CombatAnimation::Execute(Actor* actor, TESObjectREFR* target, CombatAnimation::ANIM anim)
	{
		using func_t = bool(Actor*, TESObjectREFR*, CombatAnimation::ANIM);
		REL::Relocation<func_t> func{ RELOCATION_ID(43246, 0) };  
		return func(actor, target, anim);
	}

	bool CombatAnimation::Check()
	{
		using func_t = decltype(&CombatAnimation::Check);
		REL::Relocation<func_t> func{ RELOCATION_ID(43238, 0) };  
		return func(this);
	}

	bool CombatAnimation::Execute()
	{
		using func_t = bool(CombatAnimation*);
		REL::Relocation<func_t> func{ RELOCATION_ID(43239, 0) };  
		return func(this);
	}

	bool CombatAnimation::GetEventData(const BSFixedString& event_name, float& event_time)
	{
		using func_t = bool(CombatAnimation*, const BSFixedString&, float&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43240, 0) };  
		return func(this, event_name, event_time);
	}

	bool CombatAnimation::GetEventData(const BSFixedString& event_name, float& event_time, NiPoint3& translation)
	{
		using func_t = bool(CombatAnimation*, const BSFixedString&, float&, NiPoint3&);
		REL::Relocation<func_t> func{ RELOCATION_ID(43241, 0) };  
		return func(this, event_name, event_time, translation);
	}

	float CombatAnimation::GetEventTime(const BSFixedString& event_name)
	{
		using func_t = decltype(&CombatAnimation::GetEventTime);
		REL::Relocation<func_t> func{ RELOCATION_ID(43243, 0) };  
		return func(this, event_name);
	}

	float CombatAnimation::GetLength()
	{
		using func_t = decltype(&CombatAnimation::GetLength);
		REL::Relocation<func_t> func{ RELOCATION_ID(43244, 0) };  
		return func(this);
	}

	bool CombatAnimation::GetTranslation(NiPoint3& translation)
	{
		using func_t = decltype(&CombatAnimation::GetTranslation);
		REL::Relocation<func_t> func{ RELOCATION_ID(43242, 0) };  
		return func(this, translation);
	}

	bool CombatAnimation::LoadClipData()
	{
		using func_t = decltype(&CombatAnimation::LoadClipData);
		REL::Relocation<func_t> func{ RELOCATION_ID(43247, 0) };  
		return func(this);
	}
}
