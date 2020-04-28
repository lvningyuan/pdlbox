/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


//深度优先搜索的
class Solution {
public:
    int maxDepth(Node* root) {
        int maxi = 0;
        if(!root) return 0;

        //找出所有子树中最高的那个的长度
        for(Node* it:root->children)
        {
            if(it)
                maxi = max(maxi,maxDepth(it));
        }
       
        return maxi+1; //树的长度等于最高的子树的长度+1  （参数压栈）
    }
};