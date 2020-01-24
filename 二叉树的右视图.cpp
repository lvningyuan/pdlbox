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
            res.push_back(q.back()->val);//��ÿ�����һ���ڵ�����������
            
            //while(size--)����������ر���Ҫ
            //������һ��
            while(size--)//�������еĽڵ�ĺ������
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