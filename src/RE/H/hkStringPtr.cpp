#include "RE/H/hkStringPtr.h"
#include "RE/H/hkMemoryRouter.h"

namespace RE
{
	hkStringPtr hkStringPtr::Create(const char* a_data)
	{
		auto stringPtr = hkStringPtr();
		Ctor(stringPtr, a_data);
		return stringPtr;
	}

	const char* hkStringPtr::data() const noexcept
	{
		return reinterpret_cast<const char*>(reinterpret_cast<std::uintptr_t>(_data) & ~kManaged);
	}

	const char* hkStringPtr::c_str() const noexcept
	{
		return data();
	}

	bool hkStringPtr::empty() const noexcept
	{
		return !_data || _data[0] == '\0';
	}

	auto hkStringPtr::size() const
		-> size_type
	{
		return static_cast<size_type>(std::strlen(data()));
	}

	auto hkStringPtr::length() const
		-> size_type
	{
		return size();
	}

	void hkStringPtr::Ctor(const hkStringPtr& a_stringPtr, const char* a_data)
	{
		using func_t = decltype(&hkStringPtr::Ctor);
		REL::Relocation<func_t> func{ RELOCATION_ID(56806, 57236) };
		return func(a_stringPtr, a_data);
	}
}
