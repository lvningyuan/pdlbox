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
private:
    int ret =0;
    int maxdeep =0; 

    void dfs(TreeNode* root, int deep){
        if(!root) return;

        if(deep > maxdeep)
            maxdeep += 1,ret  = root->val;
        else if(deep == maxdeep)
            ret += root->val;
        
        dfs(root->left, deep+1);
        dfs(root->right, deep+1);
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
};