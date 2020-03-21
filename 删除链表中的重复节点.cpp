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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head ==nullptr)
            return head;
        
        ListNode* cur = head->next;
        ListNode* prev = head;
        while(cur)
        {
            ListNode* tmp =cur->next; 
           if(prev -> val == cur->val)
            {
                delete cur;
                cur = tmp;
                prev -> next = cur;             
            } 
            else
            {
                prev = prev->next;
                cur = cur -> next; 
            }
        }
        return head;

    }
};