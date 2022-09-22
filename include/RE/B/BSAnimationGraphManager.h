#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSAnimationGraphChannel;
	class BShkbAnimationGraph;
	struct BSAnimationGraphEvent;

	union hkbVariableValue
	{
		bool         b;
		std::int32_t i;
		float        f;
	};
	static_assert(sizeof(hkbVariableValue) == 0x4);

	struct AnimVariableCacheInfo
	{
	public:
		// members
		BSFixedString     variableName;  // 00
		hkbVariableValue* variable;      // 08
	};
	static_assert(sizeof(AnimVariableCacheInfo) == 0x10);

	struct BSAnimationGraphVariableCache
	{
	public:
		// members
		BSTArray<AnimVariableCacheInfo>      variableCache;   // 00
		mutable BSSpinLock                   updateLock;      // 18
		BSTSmartPointer<BShkbAnimationGraph> animationGraph;  // 20 - smart ptr
#if !defined(ENABLE_SKYRIM_SE) && !defined(ENABLE_SKYRIM_VR)
		void*                           unk28;          // 28
#endif
	};
#if !defined(ENABLE_SKYRIM_SE) && !defined(ENABLE_SKYRIM_VR)
	static_assert(sizeof(BSAnimationGraphVariableCache) == 0x30);
#else
	static_assert(sizeof(BSAnimationGraphVariableCache) == 0x28);
#endif

	BSSmartPointer(BSAnimationGraphManager);

	class BSAnimationGraphManager :
		public BSTEventSink<BSAnimationGraphEvent>,  // 00
		public BSIntrusiveRefCounted                 // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSAnimationGraphManager;

		struct AnimationVariable
		{
		public:
			union Value
			{
				bool         b;
				std::int32_t i;
				float        f;
			};
			static_assert(sizeof(Value) == 0x4);

			// members
			BSFixedString name;   // 00
			Value*        value;  // 08
		};
		static_assert(sizeof(AnimationVariable) == 0x10);

		~BSAnimationGraphManager() override;  // 00

		// override (BSTEventSink<BSAnimationGraphEvent>)
		BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;  // 01

		struct RUNTIME_DATA
		{
#define RUNTIME_DATA_CONTENT                                                \
	mutable BSSpinLock                   updateLock;           /* 98, A0 */ \
	mutable BSSpinLock                   dependentManagerLock; /* A0 */     \
	std::uint32_t                        activeGraph;          /* A8 */     \
	std::uint32_t                        generateDepth;        /* A8 */

			RUNTIME_DATA_CONTENT
		};

		[[nodiscard]] inline RUNTIME_DATA& GetRuntimeData() noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x58, 0x60);
		}

		[[nodiscard]] inline const RUNTIME_DATA& GetRuntimeData() const noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x58, 0x60);
		}

		// members
		std::uint32_t                                       pad0C;                 // 0C
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>>  boundChannels;         // 10
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>>  bumpedChannels;        // 28
		BSTSmallArray<BSTSmartPointer<BShkbAnimationGraph>> graphs;                // 40
		BSTArray<BSAnimationGraphManagerPtr> subManagers;                          // 58
		BSAnimationGraphVariableCache        variableCache;                        // 70

#ifndef ENABLE_SKYRIM_AE
		RUNTIME_DATA_CONTENT
#endif
	};
#ifndef ENABLE_SKYRIM_AE
	static_assert(sizeof(BSAnimationGraphManager) == 0xB0);
#endif
}
#undef RUNTIME_DATA_CONTENT
