/*23. Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //过是能过就是时间有点久，需要优化
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *dummy = new ListNode(0);
	ListNode *tmp = dummy;
	while (l1 != NULL && l2 != NULL) {
		if (l1->val < l2->val) {
			tmp->next = l1;
			l1 = l1->next;
		}
		else {
			tmp->next = l2;
			l2 = l2->next;
		}
		tmp = tmp->next;
	}
	if (l1 != NULL) tmp->next = l1;
	else tmp->next = l2;
	return dummy->next;

}

class Solution 
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode *ans = NULL;
		for (int i = 0; i < lists.size(); i++)
		{
			ans = mergeTwoLists(ans, lists[i]);
		}
		return ans;
	}
};