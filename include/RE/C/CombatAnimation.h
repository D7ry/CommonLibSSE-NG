#pragma once

#include "RE/A/AnimationSystemUtils.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESActionData.h"

namespace RE
{
	class Actor;
	class BGSAction;
	class NiPoint3;

	class CombatAnimation : public TESActionData
	{
	public:
		virtual ~CombatAnimation() override;  // 00

		enum class ANIM : uint32_t
		{
			kActionRightAttack,
			kActionRightRelease,
			kActionRightPowerAttack,
			kActionLeftAttack,
			kActionLeftRelease,
			kActionRightAttack2,   // ranged?
			kActionRightRelease2,  // ranged?
			kActionRightInterrupt,
			kActionSneak,
			kActionActivate
		};

		enum class LoadedStatus : uint32_t
		{
			kNone,
			kSuccess,
			kFail
		};

		CombatAnimation* Ctor(Actor* a_actor, ANIM a_anim);
		CombatAnimation* Ctor(Actor* a_actor, TESObjectREFR* a_target, ANIM a_anim);
		CombatAnimation* Ctor(Actor* a_actor, BGSAction* a_action);

		static CombatAnimation* Create(Actor* a_actor, ANIM a_anim);
		static CombatAnimation* Create(Actor* a_actor, BGSAction* a_action);

		static bool Execute(Actor* a_actor, CombatAnimation::ANIM a_anim);
		static bool Execute(Actor* a_actor, TESObjectREFR* target, CombatAnimation::ANIM a_anim);

		bool  Check();
		bool  Execute();  // { return Process(); }
		bool  GetEventData(const BSFixedString& event_name, float& event_time);
		bool  GetEventData(const BSFixedString& event_name, float& event_time, NiPoint3& translation);
		float GetEventTime(const BSFixedString& event_name);
		float GetLength();
		bool  GetTranslation(NiPoint3& translation);
		bool  LoadClipData();

		// members
		BSScrapArray<AnimationSystemUtils::UtilsClipData> data;
		LoadedStatus                                      status;
		uint32_t                                          pad84;  //84
	};
	static_assert(sizeof(CombatAnimation) == 0x88);
}
