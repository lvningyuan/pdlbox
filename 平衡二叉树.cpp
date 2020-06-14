/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
class Solution {
private:
    int maxDepth(TreeNode* root){
        if(root == nullptr)  return 0;
        return max(maxDepth(root->left),            
                    maxDepth(root->right))+1;
    }
public:
    bool isBalanced(TreeNode* root) {
       if(!root) return true;
       if(abs( maxDepth(root->left) - maxDepth(root->right)) > 1)    return false;
          return isBalanced(root->left) && isBalanced(root->right);
    }
};


*/


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
    bool ans = true;
private:
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(abs(left - right) > 1) ans = false;
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
};