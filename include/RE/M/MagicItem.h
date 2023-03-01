#pragma once

#include "RE/A/ActorValues.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/M/MagicSystem.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class Actor;
	class ActorValueInfo;
	class Character;
	class EffectItem;
	class EffectSetting;
	class QueuedFile;
	class TESModel;
	class TESObjectWEAP;
	struct Effect;

	class MagicItem :
		public TESBoundObject,  // 00
		public TESFullName,     // 30
		public BGSKeywordForm   // 40
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicItem;

		class MagicItemTraversalFunctor
		{
		public:
			inline static constexpr auto RTTI = RTTI_MagicItemTraversalFunctor;

			virtual ~MagicItemTraversalFunctor(){};  // 00

			// add
			virtual BSContainer::ForEachResult Accept(Effect* a_effect) = 0;
		};

		class MagicItemDataCollector : public MagicItemTraversalFunctor
		{
		public:
			inline static constexpr auto RTTI = RTTI_MagicItemDataCollector;

			enum class Flags : uint32_t
			{
				kNone = 0,
				kSkipCostiest = 1 << 0,
				kSkipProjectiles = 1 << 1,
				kSkipArea = 1 << 2,
				kOnlyFirstEffect = 1 << 3
			};

			// override (MagicItemTraversalFunctor)
			BSContainer::ForEachResult Accept([[maybe_unused]] Effect* a_effect) override
			{
				return BSContainer::ForEachResult::kContinue;
			};  // actual function set in ctor

			MagicItemDataCollector() = delete;
			MagicItemDataCollector(const MagicItem* a_mitem);
			~MagicItemDataCollector(){};

			// members
			uint64_t                          unk08;                // 08
			BSTArray<Effect*>                 effectsProjectile;    // 10
			Effect*                           costiestEffect;       // 28
			uint32_t                          maxCost;              // 30
			uint32_t                          pad34;                // 34
			Effect*                           largestAreaEffect;    // 38
			float                             maxArea;              // 40
			stl::enumeration<Flags, uint32_t> flags;                // 44
			bool                              hasExtraLargeSummon;  // 48
			char                              pad49[7];             // 49
		};
		static_assert(sizeof(MagicItemDataCollector) == 0x50);

		class PreloadableVisitor
		{
		public:
			// add
			virtual void VisitModel(TESModel* a_model) = 0;         // 00
			virtual void VisitWeapon(TESObjectWEAP* a_weapon) = 0;  // 01
		};
		static_assert(sizeof(PreloadableVisitor) == 0x8);

		struct SkillUsageData
		{
		public:
			// members
			EffectItem*   effect;     // 00
			ActorValue    skill;      // 08
			float         magnitude;  // 0C
			bool          custom;     // 10
			std::uint8_t  pad11;      // 11
			std::uint16_t pad12;      // 12
			std::uint32_t pad14;      // 14
		};
		static_assert(sizeof(SkillUsageData) == 0x18);

		class Data
		{
		public:
			// members
			std::int32_t  costOverride;  // 0
			std::uint32_t flags;         // 4
		};
		static_assert(sizeof(Data) == 0x8);

		~MagicItem() override;  // 00

		// override (TESBoundObject)
		void InitializeData() override;          // 04 - { TESForm::InitDefaults(); }
		bool Load(TESFile* a_mod) override;      // 06
		void InitItemImpl() override;            // 13
		bool IsMagicItem() const override;       // 29 - { return true; }
		void Copy(TESForm* a_srcForm) override;  // 2F
		bool IsAutoCalc() const override;        // 3E - { return (GetData().flags & 1) == 0; }

		// override (BGSKeywordForm)
		bool HasKeyword(const BGSKeyword* a_keyword) const override;  // 04

		// add
		[[nodiscard]] virtual MagicSystem::SpellType   GetSpellType() const = 0;                                     // 53
		virtual void                                   SetCastingType(MagicSystem::CastingType a_type);              // 54 - { return; }
		[[nodiscard]] virtual MagicSystem::CastingType GetCastingType() const = 0;                                   // 55
		virtual void                                   SetDelivery(MagicSystem::Delivery a_delivery);                // 56 - { return; }
		[[nodiscard]] virtual MagicSystem::Delivery    GetDelivery() const = 0;                                      // 57
		virtual bool                                   IsValidDelivery(MagicSystem::Delivery a_delivery);            // 58 - { return true; }
		[[nodiscard]] virtual float                    GetFixedCastDuration() const;                                 // 59 - { return 0.0; }
		[[nodiscard]] virtual float                    GetRange() const;                                             // 5A - { return 0.0; }
		[[nodiscard]] virtual bool                     IgnoresResistance() const;                                    // 5B - { return false; }
		[[nodiscard]] virtual bool                     IgnoreLOS() const;                                            // 5C - { return false; }
		[[nodiscard]] virtual bool                     IsFood() const;                                               // 5D - { return false; }
		[[nodiscard]] virtual bool                     GetNoAbsorb() const;                                          // 5E - { return false; }
		[[nodiscard]] virtual bool                     GetNoDualCastModifications() const;                           // 5F - { return false; }
		virtual bool                                   GetSkillUsageData(SkillUsageData& a_data) const;              // 60 - { return false; }
		[[nodiscard]] virtual bool                     IsPoison() const;                                             // 61 - { return GetSpellType() == MagicSystem::SpellType::kPoison; }
		[[nodiscard]] virtual bool                     IsMedicine() const;                                           // 62 - { return false; }
		virtual void                                   AdjustCost(float& a_cost, Actor* a_actor) const;              // 63 - { return; }
		[[nodiscard]] virtual float                    GetChargeTime() const;                                        // 64 - { return 0.0; }
		[[nodiscard]] virtual std::uint32_t            GetMaxEffectCount() const;                                    // 65 - { return 0; }
		[[nodiscard]] virtual ActorValue               GetAssociatedSkill() const;                                   // 66 - { return ActorValue::kNone; }
		[[nodiscard]] virtual bool                     IsTwoHanded() const;                                          // 67 - { return false; }
		virtual std::uint32_t                          GetChunkID() = 0;                                             // 68
		virtual void                                   CopyMagicItemData(MagicItem* a_src) = 0;                      // 69
		virtual void                                   LoadMagicItemChunk(TESFile* a_mod, std::uint32_t a_chunkID);  // 6A - { return; }
		virtual void                                   LoadChunkDataPostProcess(TESFile* a_mod);                     // 6B - { return; }
		[[nodiscard]] virtual const Data*              GetData1() const = 0;                                         // 6C
		virtual Data*                                  GetData2() = 0;                                               // 6D
		[[nodiscard]] virtual std::uint32_t            GetDataSize() const = 0;                                      // 6E
		virtual void                                   InitFromChunk(TESFile* a_mod) = 0;                            // 6F
		virtual void                                   InitChunk() = 0;                                              // 70

		float                     CalculateMagickaCost(Actor* a_caster) const;
		float                     CalculateTotalGoldValue(Actor* a_caster = nullptr) const;
		MagicItemDataCollector    CollectData() const;
		EffectSetting*            GetAVEffectSetting() const;
		Effect*                   GetCostliestEffectItem(MagicSystem::Delivery a_delivery = MagicSystem::Delivery::kTotal, bool a_positiveArea = false) const;
		Data*                     GetData();
		[[nodiscard]] const Data* GetData() const;
		uint32_t                  GetLargestArea() const;
		uint32_t                  GetLongestDuration() const;
		bool                      IsPermanent() const;
		void                      VisitEffects(MagicItemTraversalFunctor& visitor) const;

		// members
		BSTArray<Effect*>           effects;          // 58
		std::int32_t                hostileCount;     // 70
		std::uint32_t               pad74;            // 74
		EffectSetting*              avEffectSetting;  // 78
		std::uint32_t               preloadCount;     // 80
		std::uint32_t               pad84;            // 84
		BSTSmartPointer<QueuedFile> preloadedItem;    // 88

	protected:
		float CalculateCost(Actor* a_caster) const;
	};
	static_assert(sizeof(MagicItem) == 0x90);
}
