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
    void traverse(TreeNode* root, int val)
    {
        if(root == nullptr)
        return;

        if(!root->left && !root->right)
        {
            TreeNode* newNode = new TreeNode(val);
            root->val < val ? root->right = newNode : root->left = newNode;
            return;
        }

        if(root->val > val)
        {
            if(root->left ==nullptr)
            root->left = new TreeNode(val);
            else
            traverse(root->left, val);
        }

        if(root->val < val)
        {
                        if(root->right ==nullptr)
            root->right = new TreeNode(val);
            else
        traverse(root->right, val);
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
        return new TreeNode(5);
        traverse(root, val);
        return root;
    }
};