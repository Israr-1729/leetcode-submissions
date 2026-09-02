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
    void levelSum(TreeNode* root, vector<long long> &sums)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();
            long long sum = 0;
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                sum += current->val;
                if(current->left)
                q.push(current->left);
                
                if(current->right)
                q.push(current->right);
            }
            sums.push_back(sum);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        levelSum(root, sums);
        sort(sums.rbegin(), sums.rend());

        if(sums.size() < k)
        return -1;

        return sums[k-1];
        
    }
};