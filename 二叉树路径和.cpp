给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。





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

    bool dfs(TreeNode* root, int sum,int ret)
    {
        if(!root) return false;
        
        ret += root->val;
        if(sum == ret && !root->left && !root->right)                   return true;
        else 
            return  dfs(root->left, sum, ret) || dfs(root->right, sum, ret);
        
    }



    bool hasPathSum(TreeNode* root, int sum) {
    int ret = 0;
    return dfs(root,sum,ret);
    }
};