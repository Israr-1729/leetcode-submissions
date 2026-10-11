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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;

        q.push({root, root->val});

        while(q.size() != 0)
        {
            TreeNode* front = q.front().first;
            int num = q.front().second;

            if(!front->left && !front->right)
            ans += num;

            if(front->left)
            {
                q.push({front->left, num*10 + front->left->val});
            }

            if(front->right)
            {
                q.push({front->right, num*10 + front->right->val});
            }

            q.pop();
        }
        return ans;
    }
};