/*203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.
Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = new ListNode(0);
		ListNode *ans = p;
		p->next = head;	
		while (p->next != NULL)//至少两个结点
		{
			ListNode *q = p->next;
			if (q->val == val)
				p->next = q->next;
			else
				p = q;
		}
		return ans->next;
    }
};