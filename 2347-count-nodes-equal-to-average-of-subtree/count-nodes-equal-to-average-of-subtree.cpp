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
    int sumOfSubtree(TreeNode* root)
    {
        if(root == nullptr)
        return 0;

        return sumOfSubtree(root->left) + sumOfSubtree(root->right) + root->val;
    }

    int numOfNodes(TreeNode* root)
    {
        if(root == nullptr)
        return 0;

        return numOfNodes(root->left) + numOfNodes(root->right) + 1;
    }

    int ans = 0;
    void calculate(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }

        if(root->val == sumOfSubtree(root)/numOfNodes(root))
        ans++;

        calculate(root->left);
        calculate(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        calculate(root);
        return ans;
    }
};