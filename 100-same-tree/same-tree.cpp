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
    
    vector<int> resultP;
    void preOrderP(TreeNode* root)
    {
        if(root == nullptr)
        {
        resultP.push_back(INT_MIN);
        return;
        }

        resultP.push_back(root->val);
        preOrderP(root->left);
        preOrderP(root->right);
    }

    vector<int> resultQ;
    void preOrderQ(TreeNode* root)
    {
        if(root == nullptr)
        {
            resultQ.push_back(INT_MIN);
            return;
        }

        resultQ.push_back(root->val);
        preOrderQ(root->left);
        preOrderQ(root->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preOrderP(p);
        preOrderQ(q);

        return resultP == resultQ;
    }
};