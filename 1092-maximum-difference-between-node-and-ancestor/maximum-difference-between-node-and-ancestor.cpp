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

    int maxDifference(TreeNode* root)
    {
        int rootValue = root->val;
        int maxDiff = INT_MIN;

        if(root == nullptr)
        return INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            if(current != root && abs(current->val - rootValue) > maxDiff)
            maxDiff = abs(current->val - rootValue);

            if(current->left)
            q.push(current->left);

            if(current->right)
            q.push(current->right);
        }

        return maxDiff;
    }

    void traverse(TreeNode* root, int &ans)
    {
        if(root == nullptr)
        return;

        if(maxDifference(root) > ans)
        ans = maxDifference(root);

        traverse(root->left, ans);
        traverse(root->right, ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        traverse(root, ans);
        return ans;
    }
};