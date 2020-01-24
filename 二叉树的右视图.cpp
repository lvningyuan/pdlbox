/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
       if(!root)
            return res;
     
        queue<TreeNode*> q;
        q.push(root);
 
        while(!q.empty())
        { 
            int size = q.size();
            res.push_back(q.back()->val);//将每层最后一个节点放入输出数组
            
            //while(size--)层序遍历中特别重要
            //处理下一层
            while(size--)//将队列中的节点的孩子入队
            { 
             TreeNode* head =q.front();
             q.pop();
            if(head->left)
                q.push(head->left);
            if(head->right)
                q.push(head->right);
            }
        }
        return res;
    }
};