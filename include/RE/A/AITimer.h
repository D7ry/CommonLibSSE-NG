#pragma once

namespace RE
{
	struct AITimer
	{
		static float QTimer()
		{
			using func_t = decltype(&AITimer::QTimer);
			REL::Relocation<func_t> func{ RELOCATION_ID(47089, 0) };  
			return func();
		}

		//members
		float aiTimer;  // 00
		float timer;    // 04
	};
	static_assert(sizeof(AITimer) == 0x08);
}
