#pragma once

#include "RE/BSHavok/hkMatrix3/hkMatrix3.h"


namespace RE
{
	class alignas(0x10) hkRotation : public hkMatrix3
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkRotation) == 0x30);
}
