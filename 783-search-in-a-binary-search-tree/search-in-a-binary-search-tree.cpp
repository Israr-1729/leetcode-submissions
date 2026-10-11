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
    void traverse(TreeNode* root, int val, TreeNode* &ans)
    {
        if(root == nullptr)
        return;

        if(val == root->val)
        {
            ans = root;
            return;
        }

        if(root->left && val < root->val)
        traverse(root->left, val, ans);

        if(root->right && val > root->val)
        traverse(root->right, val, ans);

    }
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* ans = nullptr;
        traverse(root, val, ans);
        return ans;

    }
};