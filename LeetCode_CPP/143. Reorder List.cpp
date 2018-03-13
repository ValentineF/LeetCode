/*143. Reorder List
Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if (head == NULL)
			return;
		vector<ListNode*> nodes;
		ListNode* iter = head;
		while (iter != NULL)
		{
			nodes.push_back(iter);
			iter = iter->next;
		}

		int LEN = nodes.size();
		int left = 0;
		int right = LEN - 1;
		while (left < right)
		{
			nodes[left]->next = nodes[right];
			nodes[right--]->next = nodes[++left];
		}
		nodes[left]->next = NULL;
    }
};