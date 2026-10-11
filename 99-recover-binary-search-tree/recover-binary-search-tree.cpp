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
    void sortedNums(TreeNode* root, vector<int> &nums)
    {
        if(root == nullptr)
        return;

        sortedNums(root->left, nums);
        nums.push_back(root->val);
        sortedNums(root->right, nums);
    }

    void change(TreeNode* root,long long p1,long long p2)
    {
        if(root==nullptr)
        return;

        if(root->val == p1)
        root->val = p2;

        else if(root->val == p2)
        root->val = p1;

        change(root->left, p1, p2);
        change(root->right, p1, p2);
    }
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        sortedNums(root, nums);
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());

        long long p1 = LLONG_MAX; long long p2 = LLONG_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != copy[i])
            {
                if(p1 == LLONG_MAX)
                p1 = nums[i];

                else
                p2 = nums[i];
            }
        }


        change(root, p1, p2);
        
    }
};