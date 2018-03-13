/*24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //不该不改，又不是数量级上的差别
class Solution 
{
public:
	ListNode* swapPairs(ListNode* head) 
    {
		if (head == NULL || head->next == NULL) 
        {
			return head;
		}
		ListNode *p, *q,*temp,*ans;
		p = head;
		q = head->next;
		ans = q;
		while (p != NULL && q != NULL)
		{
			p->next = q->next;
			q->next = p;
			temp = p;
			if (p->next != NULL)
			{
				p = p->next;
			}
			else
			{
				return ans;
			}
			if (p->next != NULL)
			{
				q = p->next;
				temp->next = q;
			}
			else
			{
				return ans;
			}
		}
		return ans;
	}
};