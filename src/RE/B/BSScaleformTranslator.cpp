#include "RE/B/BSScaleformTranslator.h"

namespace RE
{
	namespace Offset
	{
		namespace BSScaleformTranslator
		{
			inline constexpr REL::ID GetCachedString(static_cast<std::uint64_t>(69188));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(242017));
		}
	}
	void BSScaleformTranslator::GetCachedString(wchar_t** a_pOut, wchar_t* a_bufIn, std::uint32_t a_unused)
	{
		using func_t = decltype(&BSScaleformTranslator::GetCachedString);
		REL::Relocation<func_t> func{ RE::Offset::BSScaleformTranslator::GetCachedString };
		return func(a_pOut, a_bufIn, a_unused);
	}
}
