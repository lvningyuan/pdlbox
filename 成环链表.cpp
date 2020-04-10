## 一 给定一个链表，判断链表中是否有环。


*** 每次只能走1 / 2 这两种！！！


```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
    if(!head)
        return false;
    ListNode* prev =head;   
    ListNode* cur =head;
        while(cur && cur->next)
        {
            prev = prev ->next;
            cur = cur->next->next;
             if(prev == cur)
                return true;
        }
        return false;
    }
};


思路二：哈希 
将每个指针放在哈希表中。具体不实现了，太简单了