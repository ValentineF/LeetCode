/*147. Insertion Sort List
Sort a linked list using insertion sort.*/
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
    ListNode* insertionSortList(ListNode* head) {
        	ListNode *dummy = new ListNode(0);
		// 这个dummy的作用是，把head开头的链表一个个的插入到dummy开头的链表里
		// 所以这里不需要dummy->next = head;

		while (head != NULL) {
			ListNode *temp = dummy;
			ListNode *next = head->next;
			while (temp->next != NULL && temp->next->val < head->val) {
				temp = temp->next;
			}
			head->next = temp->next;
			temp->next = head;
			head = next;
		}

		return dummy->next;
    }
};