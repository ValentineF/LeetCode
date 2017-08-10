/*206. Reverse Linked List
Reverse a singly linked list.
Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        ListNode *front = new ListNode(0);
		front->next = NULL;
		while (head != NULL)
		{
			ListNode *temp = head;//一个结点
			head = head->next;
			temp->next = front->next;
			front->next	= temp;	
		}
		return front->next;
    }
};