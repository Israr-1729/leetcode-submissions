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
    int maxFreq = INT_MIN;
    void frequencer(TreeNode* root, unordered_map<int, int> &freq)
    {
        if(root == nullptr)
        return;

        freq[root->val]++;
        maxFreq = max(maxFreq, freq[root->val]);
        frequencer(root->left, freq);
        frequencer(root->right, freq);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        frequencer(root, mp);

        vector<int> ans;
        for(auto &a : mp)
        {
            if(a.second == maxFreq)
            ans.push_back(a.first);
        }

        return ans;
    }
};