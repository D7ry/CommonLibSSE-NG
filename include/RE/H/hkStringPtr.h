#pragma once

namespace RE
{
	class hkStringPtr
	{
	public:
		enum StringFlags
		{
			kManaged = 1 << 0
		};

		static hkStringPtr Create(const char* a_data);

		hkStringPtr() :
			_data(nullptr) {}


		// member types
		using size_type = std::int32_t;

		// members access
		[[nodiscard]] const char* data() const noexcept;
		[[nodiscard]] const char* c_str() const noexcept;

		// capacity
		[[nodiscard]] bool      empty() const noexcept;
		[[nodiscard]] size_type size() const;
		[[nodiscard]] size_type length() const;

	protected:
		static void Ctor(const hkStringPtr& a_stringPtr, const char* a_data);

		const char* _data;  // 0
	};
	static_assert(sizeof(hkStringPtr) == 0x8);
}
