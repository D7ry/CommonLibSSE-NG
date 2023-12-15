#include "RE/C/CombatBehaviorTree.h"

namespace RE
{
	CombatBehaviorTree::TreeBuilder::TreeBuilder(CombatBehaviorTreeNode* node)
	{
		using func_t = CombatBehaviorTree::TreeBuilder*(CombatBehaviorTree::TreeBuilder*, CombatBehaviorTreeNode * node);
		REL::Relocation<func_t> func{ RELOCATION_ID(46266, 0) };  
		func(this, node);
	}

	CombatBehaviorTreeNode* CombatBehaviorTree::TreeBuilder::GetNode()
	{
		using func_t = decltype(&CombatBehaviorTree::TreeBuilder::GetNode);
		REL::Relocation<func_t> func{ RELOCATION_ID(46257, 0) };  
		return func(this);
	}

	CombatBehaviorTree::TreeBuilder& CombatBehaviorTree::TreeBuilder::operator[](const CombatBehaviorTree::TreeBuilder& other)
	{
		using func_t = decltype(&CombatBehaviorTree::TreeBuilder::operator[]);
		REL::Relocation<func_t> func{ RELOCATION_ID(46256, 0) };  
		return func(this, other);
	}

	CombatBehaviorTree::TreeBuilder &CombatBehaviorTree::TreeBuilder::operator,(const CombatBehaviorTree::TreeBuilder&other)
	{
		using func_t = decltype(&CombatBehaviorTree::TreeBuilder::operator[]);
		REL::Relocation<func_t> func{ RELOCATION_ID(46255, 0) };  
		return func(this, other);
	}

	CombatBehaviorTree::TreeBuilder CombatBehaviorTree::AddNode(const char* name, CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&CombatBehaviorTree::AddNode);
		REL::Relocation<func_t> func{ RELOCATION_ID(46261, 0) };  
		return func(name, node);
	}

	void CombatBehaviorTree::CreateTree(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&CombatBehaviorTree::CreateTree);
		REL::Relocation<func_t> func{ RELOCATION_ID(46263, 0) };  
		return func(this, node);
	}

	CombatBehaviorTreeNode* CombatBehaviorTree::CreateLink(const char* name)
	{
		using func_t = decltype(&CombatBehaviorTree::CreateLink);
		REL::Relocation<func_t> func{ RELOCATION_ID(46262, 0) };  
		return func(name);
	}

	CombatBehaviorTree::CombatBehaviorTree(const char* name)
	{
		using func_t = CombatBehaviorTree*(CombatBehaviorTree*, const char*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46262, 0) };  
		func(this, name);
	}
}
