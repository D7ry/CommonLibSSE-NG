#pragma once
#include "hkMemoryAllocator.h"

namespace RE
{
	class hkMemoryRouter
	{
	public:
		static hkMemoryRouter& hkGetMemoryRouter();
		void*                  hkHeapAlloc(int numBytes) { return heap->BlockAlloc(numBytes); }

		uint64_t           unk00;     // 00
		uint64_t           unk08;     // 08
		uint64_t           unk10;     // 10
		uint64_t           unk18;     // 18
		uint64_t           unk20;     // 20
		uint64_t           unk28;     // 28
		uint64_t           unk30;     // 30
		uint64_t           unk38;     // 38
		uint64_t           unk40;     // 40
		uint64_t           unk48;     // 48
		hkMemoryAllocator* temp;      // 50
		hkMemoryAllocator* heap;      // 58
		hkMemoryAllocator* debug;     // 60
		hkMemoryAllocator* solver;    // 68
		void*              userData;  // 70
	};
	static_assert(offsetof(hkMemoryRouter, heap) == 0x58);
}
