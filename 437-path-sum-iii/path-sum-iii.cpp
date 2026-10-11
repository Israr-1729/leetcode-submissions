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
    int hasPathSum(TreeNode* root, int targetSum) {
        int count = 0;
        if(root == nullptr)
        return false;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, root->val});
        while(q.size() != 0)
        {
            TreeNode* front = q.front().first;
            long long currSum = q.front().second;

            if(q.front().second == targetSum)
            count++;
            
            if(front->left && currSum < 1LL*LLONG_MAX-abs(front->left->val))
            q.push({front->left, currSum + front->left->val});

            if(front->right && currSum < 1LL*LLONG_MAX-abs(front->right->val))
            q.push({front->right, currSum + front->right->val});

            q.pop();
        }
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
        return 0;

        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0)
        {
            TreeNode* front = q.front();
            count+= hasPathSum(front, targetSum);

            if(front->left)
            q.push(front->left);

            if(front->right)
            q.push(front->right);

            q.pop();
        }
        return count;
    }
};