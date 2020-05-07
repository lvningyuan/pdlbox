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
    TreeNode* dfs(vector<int>& nums,int start, int end)
    {
        if(end == start)  return nullptr;
        int mid = start + ((end-start)>>1);
        TreeNode* head = new TreeNode(nums[mid]);
      
        head->left = dfs(nums, start, mid);
        head->right = dfs(nums, mid+1, end);
        return head;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        return dfs(nums,0,nums.size());
    }
};