/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root){
        if(root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
        
        //现在root是一个光杆司令
        //   后退一层 保证root至少一个孩子
        //return ;
        if(!root->right)//直接让左子树做右子树
            swap(root->right, root->left);
        else { // 否则 兄弟  就需要做儿子孙子bulabula了
                if(root -> left){
                TreeNode* node = root->left;
                while(node->right)
                node = node -> right;

            node -> right = root -> right;
            swap(root->left, root->right);
            root -> left = nullptr;
                }
        }
    }
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root);
    }
};