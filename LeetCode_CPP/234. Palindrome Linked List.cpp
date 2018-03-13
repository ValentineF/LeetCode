/*234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //遍历取长度，然后取其一半逆置，再进行比较
ListNode* reverseList(ListNode* head)
 {
	ListNode *front = new ListNode(0);
	front->next = NULL;
	while (head != NULL)
	{
		ListNode *temp = head;//一个结点
		head = head->next;
		temp->next = front->next;
		front->next = temp;
	}
	return front->next;
}
class Solution 
{
public:
	bool isPalindrome(ListNode* head) 
	{
		if (head == NULL)
			return true;
		ListNode *p = head;
		ListNode *q = head;
		int length = 1;
		while (p->next != NULL)
		{
			p = p->next;
			length++;
		}
		if (length == 1)
			return true;
		for (int i = 1; i <= length/2; i++)
			q = q->next;
		q = reverseList(q);	
		for (int i = 1; i <= length / 2; i++)
		{
			if (head->val != q->val)
				return false;
			else
			{
				head = head->next;
				q = q->next;
			}
		}
		return true;
	}
};