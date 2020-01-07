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
    TreeNode* invertTree(TreeNode* root) {
    if(root==NULL)
    return root;
    TreeNode* tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
    }
};
／／其实也没必要设置返回值类型