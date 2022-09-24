#pragma once

#include "RE/H/hkbBehaviorGraphStringData.h"

namespace RE
{
	class hkbVariableInfo;
	struct hkbEventInfo;
	class hkbVariableBounds;
	class hkbVariableValueSet;

	struct hkbEventInfo
	{
	public:
		hkbEventInfo() :
			m_flags(Flags(0)) {}

		/// Whether or not this event should be treated as a sync point.
		bool isSyncPoint() { return (m_flags.get() & FLAG_SYNC_POINT) != 0; }

		/// Whether or not this event should be raised by clip generators.
		bool isSilent() { return (m_flags.get() & FLAG_SILENT) != 0; }

		/// Definitions of flags that influence the behavior of events.
		enum Flags
		{
			/// Whether or not clip generators should raise the event.
			FLAG_SILENT = 0x1,

			/// Whether or not the sync point will be
			FLAG_SYNC_POINT = 0x2,
		};

		/// The flags that influence the behavior of events.
		stl::enumeration<Flags, std::uint32_t> m_flags;
	};
	static_assert(sizeof(hkbEventInfo) == 0x4);

	class hkbBehaviorGraphData : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBehaviorGraphData;

		virtual ~hkbBehaviorGraphData() = default;  // 00

		// members
		hkArray<float>                       attributeDefaults;       // 10
		hkArray<hkbVariableInfo>             variableInfos;           // 20
		hkArray<hkbVariableInfo>             characterPropertyInfos;  // 30
		hkArray<hkbEventInfo>                eventInfos;              // 40
		hkArray<hkbVariableBounds>           variableBounds;          // 50
		uint64_t                             unk60;                   // 60
		uint64_t                             unk68;                   // 68
		hkbVariableValueSet*                 variableInitialValues;   // 70
		hkRefPtr<hkbBehaviorGraphStringData> stringData;              // 78
	};
	static_assert(sizeof(hkbBehaviorGraphData) == 0x80);
}
