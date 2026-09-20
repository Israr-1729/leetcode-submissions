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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        if(root == nullptr)
        return 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* &thisNode = q.front();
                if(thisNode->left) q.push(thisNode->left);
                if(thisNode->right) q.push(thisNode->right);
                q.pop();
            }
        maxDepth++;
        }
        return maxDepth;
    }
};