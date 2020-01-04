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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;
        return A(root,root);
    }
    bool A(TreeNode* bt1,TreeNode*bt2)
    {
        if(!bt1 && !bt2)//左右均不存在
        return true; 
        if(!bt1 || !bt2)//一边不存在
        return false;
            if(bt1->val ==bt2->val)//均存在
            return A(bt1->left,bt2->right)&&  A(bt2->left,bt1->right);
            //比较A的左  和B的右   并且A的右 和 B的左
            return false;//存在却不相等
          
    }
};