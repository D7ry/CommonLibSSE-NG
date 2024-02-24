#include "RE/E/ExtraStartingPosition.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	void ExtraStartingPosition::SetStartingPosition(TESObjectREFR* a_refr, const NiPoint3& a_position, const NiPoint3& a_rotation, BGSLocation* a_location)
	{
		using func_t = decltype(&ExtraStartingPosition::SetStartingPosition);
		REL::Relocation<func_t> func{ RELOCATION_ID(11851, 11990) };
		return func(this, a_refr, a_position, a_rotation, a_location);
	}
}
