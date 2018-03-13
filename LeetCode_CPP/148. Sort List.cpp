/*148. Sort List
Sort a linked list in O(n log n) time using constant space complexity.*/
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
    ListNode* sortList(ListNode* head) {
        ListNode *ans = head;
		ListNode *p = head;
		vector<int> a;
		while (p != NULL)
		{
			a.push_back(p->val);
			p = p->next;
		}
		sort(a.begin(), a.end());
		int i = 0;
		while (head != NULL)
		{
			head->val = a[i++];
			head = head->next;
		}
		return ans;
    }
};