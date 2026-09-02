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
    void traverse(vector<int> &result, TreeNode* root)
    {
        if(root == nullptr)
        return;

        result.push_back(root->val);

        traverse(result, root->left);
        traverse(result, root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        traverse(result, root);
        sort(result.begin(), result.end());
        return result[k-1];
    }
};