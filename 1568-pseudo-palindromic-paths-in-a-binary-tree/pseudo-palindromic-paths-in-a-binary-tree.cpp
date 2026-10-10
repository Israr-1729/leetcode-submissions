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
    void findAnswer(TreeNode* root, int mask, int &ans)
    {
        if(root == nullptr)
        return;

        mask ^= (1 << root->val);

        if(!root->left && !root->right && (mask & (mask - 1)) == 0)
        ans++;

        findAnswer(root->left, mask, ans);
        findAnswer(root->right, mask, ans);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        findAnswer(root, 0, ans);
        return ans;
    }
};
