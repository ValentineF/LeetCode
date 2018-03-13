/*445. Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>  s1, s2, s3;
		ListNode *ans = new ListNode(0);
		ListNode *head = ans;	
		int  sum = 0, add = 0;
		while (l1 != NULL)
		{
			s1.push(l1->val);
			l1 = l1->next;			
		}
		while (l2 != NULL)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}
		while (!s1.empty() || !s2.empty())
		{
			if (s1.empty())//用完了就用0替代直到都出栈
				s1.push(0);
			if (s2.empty())
				s2.push(0);
			sum += s1.top() + s2.top();
			add = sum % 10;
			s3.push(add);
			s1.pop();
			s2.pop();
			sum = sum / 10;			
		}
		if (sum > 0)//最后还有进位
			s3.push(sum);
		if(s3.top() == 0 && s3.size() == 1)//若数为0
				return new ListNode(0);
		while (!s3.empty())
		{
			ListNode *temp = new ListNode(s3.top());
			head->next = temp;
			head = head->next;
			s3.pop();
		}
		return ans->next;
    }
};