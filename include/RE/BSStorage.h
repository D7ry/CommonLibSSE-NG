#pragma once

#include <winnt.h>  // PLARGE_INTEGER, LARGE_INTEGER
#include <minwindef.h>  // BOOL, DWORD, LPVOID, LPCVOID

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	class BSStorage : public BSIntrusiveRefCounted
	{
	public:
		virtual ~BSStorage();																			// 00

		// add
		virtual PLARGE_INTEGER 	GetFileSize() = 0;														// 01
		virtual PLARGE_INTEGER	GetFilePointer() = 0;													// 02
		virtual BOOL			SetFilePointer(LARGE_INTEGER a_distanceToMove, DWORD a_moveMethod) = 0;	// 03
		virtual BOOL			ReadFile(DWORD a_numberOfBytesToRead, LPVOID a_buffer) = 0;				// 04
		virtual BOOL			WriteFile(DWORD a_numberOfBytesToWrite, LPCVOID a_buffer) = 0;			// 05


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(BSStorage) == 0x20);
}