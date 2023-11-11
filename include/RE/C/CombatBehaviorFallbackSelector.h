#pragma once

#include "RE/C/CombatBehaviorChildSelector.h"
#include "RE/N/NextChildSelector.h"
#include "RE/W/WeightedRandomChildSelector.h"

namespace RE
{
	template <typename Selector>
	class CombatBehaviorFallbackSelector : public CombatBehaviorNode, public Selector
	{
	public:
		static bool Validate(CombatBehaviorTreeNode* node)
		{
			return CombatBehaviorNode::Validate(node) && Selector::Validate(node);
		}

		void Enter()
		{
			auto cur_thread = GetStaticTLSData()->combatAIThread;
			auto ind = Selector::SelectChild(cur_thread->active_node, CurrentChild);
			CurrentChild = ind;
			if (ind == -1) {
				cur_thread->SetFailed(true);
				cur_thread->Ascend();
			} else {
				cur_thread->Descend(ind);
			}
		}

		void Update()
		{
			auto cur_thread = GetStaticTLSData()->combatAIThread;
			if (cur_thread->fail_state == CombatBehaviorThread::FailState::kFailed) {
				cur_thread->SetFailed(false);
				this->Enter();
			} else {
				cur_thread->Ascend();
			}
		}

		// members
		uint32_t CurrentChild;
	};
}
