#pragma once

#include "RE/B/BSTTuple.h"
#include "RE/C/CombatBehaviorStack.h"

namespace RE
{
	class CombatBehaviorController;
	class CombatBehaviorTreeNode;

	class CombatBehaviorThread
	{
	public:
		enum class FailState : uint32_t
		{
			kOk,
			kFailed,
			kAborted
		};

		enum class State : uint32_t
		{
			kAscended,
			kProcessing,
			kDescended
		};

		enum class Flags : uint32_t
		{
			kPaused = 1 << 0,
			kSuspended = 1 << 1,
			kUnk2 = 1 << 2,
			kIsWorking_mb = 1 << 3
		};

		CombatBehaviorThread(CombatBehaviorController* parent_control, CombatBehaviorThread* parent_thread);
		~CombatBehaviorThread();

		template <typename T>
		T& GetCurrentStackObject()
		{
			return stack.Access<T>(stack_for_cur_node);
		}

		template <typename T>
		T* GetCurrentContext()
		{
			return cur_context_sptr.stack ? &cur_context_sptr.stack->Access<T>(cur_context_sptr.frame) : nullptr;
		}

		void     Abort();
		void     AddChildThread(CombatBehaviorThread* thread);
		void     Ascend();
		void     Ascend(CombatBehaviorTreeNode* node);
		bool     CheckRelated(CombatBehaviorThread* other) const;
		bool     CheckParent(CombatBehaviorThread* is_parent) const;
		void     Descend(uint32_t ind = 0);
		void     Descend(CombatBehaviorTreeNode* ind);
		bool     GetAscendingUpdate() const;
		uint32_t GetChildIndex() const;
		bool     GetInitialUpdate() const;
		void     Pause();
		void     Resume();
		void     SetAborted();
		void     SetFailed(bool failed);
		void     Suspend();
		void     Update();
		void     Unpause();
		void     Unsuspend();

		// members
		CombatBehaviorStack                                            stack;               // 000
		BSTSmallArray<BSTTuple<CombatBehaviorTreeNode*, uint32_t>, 16> stack_layout;        // 010
		uint32_t                                                       stack_for_cur_node;  // 120
		uint32_t                                                       pad_124;             // 124
		CombatBehaviorStack::ObjectPtr                                 cur_context_sptr;    // 128
		CombatBehaviorTreeNode*                                        active_node;         // 138
		CombatBehaviorTreeNode*                                        prev_active_node;    // 140
		FailState                                                      fail_state;          // 148
		State                                                          state;               // 14C
		stl::enumeration<Flags, uint32_t>                              flags;               // 150
		uint32_t                                                       index_in_control;    // 154
		CombatBehaviorController*                                      control;             // 158
		CombatBehaviorThread*                                          parent;              // 160
		BSTSmallArray<CombatBehaviorThread*, 4>                        child_threads;       // 168
	};
	static_assert(sizeof(CombatBehaviorThread) == 0x198);
}
