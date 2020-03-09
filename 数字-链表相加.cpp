
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 =l1;
        ListNode* t2 =l2;
        int tmp=0;//进位
        ListNode* tail  = new ListNode(0);
        ListNode* flag = tail;
        while(t1 && t2)
        {
            ListNode* head =new ListNode(0);
             int value = t1->val + t2->val + tmp;
            if(value < 10)
            {
                head-> val = value;
                tmp = 0;
            }
            else
            {
                tmp = 1;
                head->val = value - 10;
            }
             t1 = t1 ->next;
             t2 = t2 ->next; 
             tail->next = head;
             tail = tail->next;
    }
    while(t1)
    {
        int value  = t1->val + tmp;
        ListNode* newhead = new ListNode(0);
        if(value < 10)
        {
            newhead->val = value;
            tmp = 0;
        }
        else 
        {
            newhead->val = value -10; 
            tmp = 1; 
        }
        tail->next = newhead;
        t1 = t1->next; 
        tail = tail->next;
    }
    
   while(t2)
    {
        int value  = t2->val + tmp;
        ListNode* newhead = new ListNode(0);
        if(value < 10)
        {
            newhead->val = value;
            tmp = 0;
        }
        else 
        {
            newhead->val = value -10; 
            tmp = 1; 
        }
        tail->next = newhead;
        t2 = t2->next; 
        tail = tail->next;
    }
    if(tmp != 0)
    {
       ListNode* newHead = new ListNode(tmp);
       tail->next = newHead;
    }
    
    ListNode* newtail = flag->next;
    delete(flag);
    return newtail;
    }
};