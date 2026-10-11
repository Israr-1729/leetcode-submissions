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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr)
        return 0;

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size() != 0)
        {
            TreeNode* front = q.front(); 

            if(front->left)
            q.push(front->left);

            if(front->right)
            q.push(front->right);

            if(front->val >= low && front->val <= high)
            ans += front->val;
            q.pop();
        }
        return ans;
    }
};