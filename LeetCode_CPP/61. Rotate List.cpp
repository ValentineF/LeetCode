/*61. Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //截取长度，然后直接粘上去就好了
class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == NULL)
			return NULL;
		ListNode *p1 = head;
		ListNode *p2 = head;
		int length = 1;
		while (p1->next != NULL)
		{
			p1 = p1->next;
			length++;
		}
		int pos1 = k % length;//K
		if (pos1 == 0)
			return head;
		int pos2 = length - pos1; //从头开始的数
		for (int i = 0; i < pos2-1; i++)
		{
			p2 = p2->next;
		}
		ListNode *ans = p2->next;
		p2->next = NULL;
		p1->next = head;
		return ans;
    }
};