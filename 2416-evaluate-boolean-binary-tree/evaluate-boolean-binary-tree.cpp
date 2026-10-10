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
    void transform(TreeNode* root)
    {
        if(root->left == nullptr)
        return; 

        transform(root->left);
        transform(root->right);

        if(root->left->val == 1 || root->left->val == 0 || root->right->val == 1 || root->right->val == 0)
        {
            if(root->val == 2)
            root->val = (root->left)->val || (root->right)->val;

            if(root->val == 3)
            root->val = (root->left)->val && (root->right)->val;
        }
    }
    bool evaluateTree(TreeNode* root) {
        transform(root);
        return root->val;
    }
};