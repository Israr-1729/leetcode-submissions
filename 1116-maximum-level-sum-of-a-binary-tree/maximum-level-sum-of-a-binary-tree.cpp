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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int level = 1;
        int ans = 0;
        //if(root == nullptr)
        //return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            int sum = 0;

            for(int i = 0; i < size; i++)
            {
                sum += q.front()->val;
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);

                q.pop();
            }

            if(sum > maxSum)
            {
            ans = level;
            maxSum = sum;
            }

            level++;

        }
        return ans;
    }
};