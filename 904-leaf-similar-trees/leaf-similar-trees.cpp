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
    void fill(TreeNode* root, vector<int> &nodes)
    {
        if(root == nullptr)
        return;

        if(!root->left && !root->right)
        nodes.push_back(root->val);

        fill(root->left, nodes);
        fill(root->right, nodes);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> val1;
        vector<int> val2;
        fill(root1, val1);
        fill(root2, val2);

        return val1 == val2;
        
    }
};