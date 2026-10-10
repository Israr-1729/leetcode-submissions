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
    bool isPseudoPalindromic(vector<int> &nums)
    {
        int numOdd = 0;
        for(int i : nums)
        {
            if(i%2 != 0)
            {
                numOdd++;
            }
            if(numOdd > 1)
            return false;
        }
        return true;
    }

    void findAnswer(TreeNode* root, int &ans)
    {
        vector<int> nums(10, 0);
        if(root == nullptr)
        return;

        queue<pair<TreeNode*, vector<int>>> q;
        q.push({root, nums});

        while(q.size() != 0)
        {

            TreeNode* front = q.front().first;
            q.front().second[front->val]++;
            if(!front->left && !front->right && isPseudoPalindromic(q.front().second))
            ans++;

            if(front->left)
            {
                q.push({front->left, q.front().second});
            }

            if(front->right)
            {
                q.push({front->right, q.front().second});
            }

            q.pop();
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        findAnswer(root, ans);
        return ans;
    }
};