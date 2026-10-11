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
    vector<int> values(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while(q.size() != 0)
        {
            TreeNode* front = q.front();
            result.push_back(front->val);

            if(front->left)
            q.push(front->left);

            if(front->right)
            q.push(front->right);

            q.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> result = values(root);
        for(int i = 0; i < result.size()-1; i++)
        {
            ans = min(result[i+1]-result[i], ans);
        }
        return ans;
    }
};