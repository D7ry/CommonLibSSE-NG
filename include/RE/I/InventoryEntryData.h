#pragma once

#include "RE/B/BSTList.h"
#include "RE/E/ExtraDataList.h"
#include "RE/F/FormTypes.h"
#include "RE/M/MemoryManager.h"
#include "RE/S/SoulLevels.h"

namespace RE
{
	class ExtraDataList;
	class TESBoundObject;

	class InventoryEntryData
	{
	public:
		InventoryEntryData() noexcept = default;
		InventoryEntryData(const InventoryEntryData& a_rhs);

		InventoryEntryData(InventoryEntryData&& a_rhs) noexcept :
			object(std::exchange(a_rhs.object, nullptr)),
			extraLists(std::exchange(a_rhs.extraLists, nullptr)),
			countDelta(std::exchange(a_rhs.countDelta, 0))
		{}

		InventoryEntryData(TESBoundObject* a_object, std::int32_t a_countDelta) :
			object(a_object),
			countDelta(a_countDelta)
		{}

		~InventoryEntryData();

		InventoryEntryData& operator=(const InventoryEntryData& a_rhs);
		InventoryEntryData& operator=(InventoryEntryData&& a_rhs);

		void                                          AddExtraList(ExtraDataList* a_extra);
		[[nodiscard]] const char*                     GetDisplayName();
		[[nodiscard]] std::optional<double>           GetEnchantmentCharge() const;
		[[nodiscard]] constexpr TESBoundObject*       GetObject__() noexcept { return object; }
		[[nodiscard]] constexpr const TESBoundObject* GetObject__() const noexcept { return object; }
		[[nodiscard]] TESForm*                        GetOwner();
		[[nodiscard]] SOUL_LEVEL                      GetSoulLevel() const;

		[[nodiscard]] std::int32_t GetValue() const
		{
			using func_t = decltype(&InventoryEntryData::GetValue);
			REL::Relocation<func_t> func{ RELOCATION_ID(15757, 15995) };
			return func(this);
		}

		[[nodiscard]] float GetWeight() const;
		[[nodiscard]] bool  IsEnchanted() const;
		[[nodiscard]] bool  IsFavorited() const;
		[[nodiscard]] bool  IsLeveled() const;
		[[nodiscard]] bool  IsPoisoned() const;
		[[nodiscard]] bool  IsWorn() const;

		[[nodiscard]] bool IsOwnedBy(Actor* a_testOwner, bool a_defaultTo = true)
		{
			return IsOwnedBy(a_testOwner, GetOwner(), a_defaultTo);
		}

		[[nodiscard]] bool IsOwnedBy(Actor* a_testOwner, TESForm* a_itemOwner, bool a_defaultTo = true)
		{
			return IsOwnedBy_Impl(a_testOwner, a_itemOwner, a_defaultTo);
		}

		[[nodiscard]] bool IsQuestObject() const
		{
			using func_t = decltype(&InventoryEntryData::IsQuestObject);
			REL::Relocation<func_t> func{ RELOCATION_ID(15767, 16005) };
			return func(this);
		}

		void PoisonObject(AlchemyItem* a_alchItem, std::uint32_t a_count)
		{
			using func_t = decltype(&InventoryEntryData::PoisonObject);
			REL::Relocation<func_t> func{ RELOCATION_ID(15786, 16024) };
			return func(this, a_alchItem, a_count);
		}

		TES_HEAP_REDEFINE_NEW();

		// members
		TESBoundObject*               object{ nullptr };      // 00
		BSSimpleList<ExtraDataList*>* extraLists{ nullptr };  // 08
		std::int32_t                  countDelta{ 0 };        // 10
		std::uint32_t                 pad14{ 0 };             // 14

	private:
		[[nodiscard]] bool IsOwnedBy_Impl(Actor* a_testOwner, TESForm* a_itemOwner, bool a_defaultTo)
		{
			using func_t = decltype(&InventoryEntryData::IsOwnedBy_Impl);
			REL::Relocation<func_t> func{ RELOCATION_ID(15782, 16020) };
			return func(this, a_testOwner, a_itemOwner, a_defaultTo);
		}

		template <class T>
		[[nodiscard]] bool HasExtraDataType() const
		{
			if (extraLists) {
				for (const auto& xList : *extraLists) {
					if (xList && xList->HasType<T>()) {
						return true;
					}
				}
			}

			return false;
		}
	};
	static_assert(sizeof(InventoryEntryData) == 0x18);
}
