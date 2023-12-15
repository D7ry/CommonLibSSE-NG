#include "RE/C/CombatBehaviorDynamicConditionalNode.h"

namespace RE
{
	bool CombatBehaviorDynamicConditionalNode::Validate(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&CombatBehaviorDynamicConditionalNode::Validate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46183, 0) };  
		return func(node);
	}

	CombatBehaviorDynamicConditionalNode::CombatBehaviorDynamicConditionalNode(float interval)
	{
		using func_t = CombatBehaviorDynamicConditionalNode*(CombatBehaviorDynamicConditionalNode*, float);
		REL::Relocation<func_t> func{ RELOCATION_ID(46176, 0) };  
		func(this, interval);
	}

	void CombatBehaviorDynamicConditionalNode::Abort()
	{
		using func_t = decltype(&CombatBehaviorDynamicConditionalNode::Abort);
		REL::Relocation<func_t> func{ RELOCATION_ID(46180, 0) };  
		return func(this);
	}

	void CombatBehaviorDynamicConditionalNode::Enter()
	{
		using func_t = decltype(&CombatBehaviorDynamicConditionalNode::Enter);
		REL::Relocation<func_t> func{ RELOCATION_ID(46178, 0) };  
		return func(this);
	}

	void CombatBehaviorDynamicConditionalNode::Update()
	{
		using func_t = decltype(&CombatBehaviorDynamicConditionalNode::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(46179, 0) };  
		return func(this);
	}
}
