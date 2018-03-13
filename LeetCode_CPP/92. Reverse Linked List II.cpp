/*92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* head) {
	ListNode *front = new ListNode(0);
	front->next = NULL;
	while (head != NULL){
		ListNode *temp = head;//一个结点
		head = head->next;
		temp->next = front->next;
		front->next = temp;
	}
	return front->next;
}
class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || m == n)
			return head;
		ListNode *ans = new ListNode(0);
		ans->next = head;
		ListNode *p = ans;
		ListNode *q1, *q2, *pre, *cur;
		int pos = 0;
		while (p != NULL){
			if (pos == m - 1)//前一个
				pre = p;
			if (pos == m)//首
				q1 = p;
			if (pos == n)//尾
				q2 = p;
			p = p->next;
			pos++;
		}
		//保存尾巴
		cur = q2->next;
		//反转，接到头部
		q2->next = NULL;		
		pre->next = reverseList(q1);
		//接上尾巴
		while (pre->next != NULL)
			pre = pre->next;
		pre->next = cur;
		return ans->next;
	}
};