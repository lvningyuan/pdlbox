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
    vector<TreeNode*> ret;
private:
    //因为涉及指针的修改 ：  因此必须传二级指针或者一级指针的引用
    void dfs(TreeNode* & root, unordered_set<int>&del){
        if(!root) return;
        if(root->left)
            dfs(root->left, del);
        if(root->right)
            dfs(root->right,del);
        
        if(del.find(root->val) != del.end()){
           if(root->left)
                ret.push_back(root->left);
           if(root->right)
                ret.push_back(root->right);
            root = nullptr;//可能存在内存泄漏问题
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ret.clear();
           unordered_set<int> del(to_delete.begin(), to_delete.end());
        dfs(root, del);
        if (root)
            ret.push_back(root);
        return ret;
    }
};