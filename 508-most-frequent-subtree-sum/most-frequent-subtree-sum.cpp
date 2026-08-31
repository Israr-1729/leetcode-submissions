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
    unordered_map<int, int> freq;

    int sum(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
    int currentSum = leftSum + rightSum + root->val;
    freq[currentSum]++;
    return currentSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        int totalSum = sum(root);
        vector<int> maxSum;
        int maxFreq = -1;
        for(auto &a : freq)
        {
            if(a.second > maxFreq)
            {
                maxFreq = a.second;
            }
        }

        for(auto &a : freq)
        {
            if(a.second == maxFreq)
            maxSum.push_back(a.first);
        }




        return maxSum;
    }
};