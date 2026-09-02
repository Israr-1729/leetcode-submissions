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
    bool isDecreasing(const vector<int> &nums)
    {
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] <= nums[i+1])
            return false;
        }
        return true;
    }

    bool isIncreasing(const vector<int> &nums)
    {
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] >= nums[i+1])
            return false;
        }
        return true;
    }

    void answer(TreeNode* root, bool &ans)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);

        int currLevel = 0;
        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> nums;
            for(int i  = 0; i < levelSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                nums.push_back(curr->val);

                if(curr->left)
                q.push(curr->left);

                if(curr->right)
                q.push(curr->right);
            }
        if(currLevel % 2 == 0)
        {
            for(int x : nums)
            {
                if(x % 2 == 0)
                {
                    ans = false;
                    return;
                }
            }

            if(!isIncreasing(nums))
            {
                ans = false;
                return;
            }
        }

        else
        {
            for(int x : nums)
            {
                if(x % 2 != 0)
                {
                    ans = false;
                    return;
                }
            }

            if(!isDecreasing(nums))
            {
                ans = false;
                return;
            }
        }
            currLevel++;
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        bool ans = true;
        answer(root, ans);
        return ans;
    }
};