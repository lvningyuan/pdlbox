class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        while(q1.size() > 1)//找到最后入队的元素
        {
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
        }
        int tmp = q1.front();
        q1.pop();
        while (!q2.empty())//元素出栈后，恢复到未进栈之前的状态
        {
            int t = q2.front();
            q2.pop();
            q1.push(t);
        }
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
        
    }
    private:
    queue<int> q1;
    queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */