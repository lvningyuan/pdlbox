/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    int  getHeight(TreeNode* root)
    {
        if(!root) return 0;
        return max(getHeight(root->left),getHeight(root->right)) + 1;
    }

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        //本层成立不代表层层成立  ， 本层不成立整棵树必定不成立
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1)  return false;

        return isBalanced(root->left) && isBalanced(root->right); 
    } 
};