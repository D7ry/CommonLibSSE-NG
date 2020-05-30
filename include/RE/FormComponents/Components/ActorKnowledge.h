#pragma once

#include "RE/FormComponents/Components/AITimeStamp.h"
#include "RE/BSCore/BSPointerHandle.h"
#include "RE/FormComponents/Enums/FightReactions.h"
#include "RE/NetImmerse/NiRefObject/NiRefObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class DetectionListener;
	class DetectionState;


	class ActorKnowledge : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorKnowledge;


		enum class FLAGS : UInt32
		{
			kNone = 0
		};


		virtual ~ActorKnowledge();	// 00


		// members
		ActorHandle							   owner;						 // 10
		ActorHandle							   target;						 // 14
		FIGHT_REACTION						   factionFightReaction;		 // 18
		AITimeStamp							   shouldAttackTargetTimeStamp;	 // 1C
		NiPointer<DetectionState>			   detectionState;				 // 20
		BSTArray<NiPointer<DetectionListener>> listeners;					 // 28
		FLAGS								   flags;						 // 40
		AITimeStamp							   detectionQueuedTimeStamp;	 // 44
	};
	STATIC_ASSERT(sizeof(ActorKnowledge) == 0x48);
}
