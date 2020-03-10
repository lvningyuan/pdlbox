/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


1。创建新节点，尾插法

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr)
            return head;

        ListNode*  Head = new ListNode(head->val);
        Head ->next = nullptr;
        
        while(head->next)
        {
            head = head->next; 
            ListNode* tmp =new ListNode(head->val);
            tmp->next = Head;
            Head= tmp;     
        }
        return Head;
    }
};

2。  原地更新，O（1）辅助空间
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        
        ListNode* cur = head;
        while(cur)
        {
            ListNode* tmp = cur->next;//保存一下下一个节点的指针
            cur -> next = prev;
            prev = cur;//迭代更新
            cur = tmp; //迭代更新
        }
        return prev;
    }
};


3。交换法。


	class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        
        while(head)
	{
	    swap(head->next, prev);
	    swap(head, prev);
	}
        return prev;
    }
};
