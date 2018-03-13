/*82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL || head->next == NULL){  
            return head;  
        }  
        ListNode *p = new ListNode(-1);  
        p->next = head;  
        ListNode *cur = p, *pre = head;  
        while(pre != NULL){  
            bool isDupli = false;  
            while(pre->next != NULL && pre->val == pre->next->val){  
                isDupli = true;  
                pre = pre->next;  
            }  
            if(isDupli){  
                pre = pre->next;  
                continue;  
               
            }  
            cur->next = pre;  
            cur = cur->next;  
            pre = pre->next;  
              
        }  
        cur->next = pre;  
        return p->next;  
    }
};