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
    void frequencer(TreeNode* root, unordered_map<int, int> &freq)
    {
        if(root == nullptr)
        return;

        freq[root->val]++;
        frequencer(root->left, freq);
        frequencer(root->right, freq);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        frequencer(root, mp);

        int highestFreq = -1;
        for(auto &a : mp)
        {
            highestFreq = max(highestFreq, a.second);
        }

        vector<int> ans;
        for(auto &a : mp)
        {
            if(a.second == highestFreq)
            ans.push_back(a.first);
        }

        return ans;
    }
};