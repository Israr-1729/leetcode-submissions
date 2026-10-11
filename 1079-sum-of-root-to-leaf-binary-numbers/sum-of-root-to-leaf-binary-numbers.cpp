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
    int sumRootToLeaf(TreeNode* root) {
        if(root->val == 0 && !root->left && !root->right)
        return 0;

        if(root->val == 1 && !root->right && !root->left)
        return 1;

        int ans = 0;
        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});

        while(q.size() != 0)
        {
            TreeNode* front = q.front().first;

            if(!front->left && !front->right)
            {
                ans += stoi(q.front().second, nullptr, 2);
            }

            if(front->left)
            {
                q.push({front->left, q.front().second + (char)(front->left->val + '0')});
            }

            if(front->right)
            {
                q.push({front->right, q.front().second + (char)(front->right->val + '0')});
            }
            q.pop();
        }
        return ans;
    }
};