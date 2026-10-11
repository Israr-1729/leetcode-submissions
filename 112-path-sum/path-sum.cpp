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
    bool pathSums(TreeNode* root, int targetSum)
    {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, root->val});
        while(q.size() != 0)
        {
            TreeNode* front = q.front().first;
            int currSum = q.front().second;

            if(!front->left && !front->right)
            {
                if(q.front().second == targetSum)
                return true;
            }

            if(front->left)
            q.push({front->left, currSum + front->left->val});

            if(front->right)
            q.push({front->right, currSum + front->right->val});

            q.pop();
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
        return false;
        
        return pathSums(root, targetSum);
    }
};