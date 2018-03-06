#pragma once
namespace linkedNodeofclasses{
	class ListNode
	{
	public:
		ListNode();
		~ListNode();

		int val;
		ListNode *next;
		ListNode(int x);
	};
}