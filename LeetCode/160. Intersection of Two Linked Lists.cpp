/*160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.
Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode *pa = headA;
		ListNode *pb = headB;
		int lengthA = 1;
		int lengthB = 1;
		while (pa->next != NULL)
		{
			pa = pa->next;
			lengthA++;
		}
		while (pb->next != NULL)
		{
			pb = pb->next;
			lengthB++;
		}
		if (pa != pb)
			return NULL;
		if (lengthA > lengthB)
		{
			for (int i = 0; i < lengthA-lengthB; i++)
				headA = headA->next;
		}
		else if(lengthB > lengthA)
		{
			for (int i = 0; i < lengthB-lengthA; i++)
				headB = headB->next;
		}
		while (headA != headB)
		{
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
};