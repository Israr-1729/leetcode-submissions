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
    void traverse(TreeNode* root, int val, bool &ans)
    {
        if(root == nullptr)
        {
            ans = true;
            return;
        }

        if(root->val != val)
        {
            ans = false;
            return;
        }

        if(root->left)
        traverse(root->left, val, ans);
        if(root->right)
        traverse(root->right, val, ans);
    }
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        bool ans = true;
        traverse(root, val, ans);
        return ans;
        
    }
};