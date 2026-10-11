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
    void numsGiver(TreeNode* root, vector<int> &nums, unordered_set<int> &copy)
    {
        if(root == nullptr)
        return;

        numsGiver(root->left, nums, copy);

        nums.push_back(root->val);
        copy.insert(root->val);

        numsGiver(root->right, nums, copy);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        unordered_set<int> copy;
        numsGiver(root, nums, copy);

        for(int i : nums)
        {
            int complement = k - i;
            if(copy.contains(complement) && i != complement)
            return true;
        }
        return false;
    }
};