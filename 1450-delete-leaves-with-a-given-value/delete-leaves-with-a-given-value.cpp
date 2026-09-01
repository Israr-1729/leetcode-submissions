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
    bool isLeaf(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr)
        return true;

        return false;
    }

    bool contains(TreeNode* root, int target)
    {
        if(root == nullptr)
        return false;

        if(isLeaf(root) && root->val == target)
        return true;

        return contains(root->left, target) || contains(root->right, target);
    }
    void traverse(TreeNode* root, int target)
    {
        if(root == nullptr)
        return;

        if(root->left && isLeaf(root->left) && root->left->val == target)
        root->left = nullptr;

        if(root->right && isLeaf(root->right) && root->right->val == target)
        root->right = nullptr;

        traverse(root->left, target);
        traverse(root->right, target);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        while(contains(root, target))
        {
            traverse(root, target);
            if(isLeaf(root) && root->val == target)
            return nullptr;
        }
        return root;
    }
};