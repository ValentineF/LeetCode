/*141. Linked List Cycle
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //设置两个快慢指针看能否相遇
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
			return false;
		ListNode *fast = head->next;
		ListNode *slow = head;
		while (fast != NULL && fast->next != NULL)
		{
			if (fast == slow)
				return true;
			slow = slow->next;
			fast = fast->next->next;				
		}
		return false;
    }
};