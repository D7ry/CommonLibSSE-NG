#pragma once

#include "RE/hkpAllCdPointCollector.h"  // hkpAllCdPointCollector


namespace RE
{
	class bhkCharacterPointCollector : public hkpAllCdPointCollector
	{
	public:
		virtual ~bhkCharacterPointCollector();	// 00


		// members
		UInt64	unk220;	// 220
		UInt64	unk228;	// 228
		UInt64	unk230;	// 230
		UInt64	unk238;	// 238
	};
	STATIC_ASSERT(sizeof(bhkCharacterPointCollector) == 0x240);
}