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
public:
    void lot(TreeNode* root, vector<int> &ans)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> thisArray;
            for(int i = 0; i < size; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                thisArray.push_back(current->val);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            ans.push_back(thisArray.back());
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        lot(root, ans);
        return ans;
    }
};