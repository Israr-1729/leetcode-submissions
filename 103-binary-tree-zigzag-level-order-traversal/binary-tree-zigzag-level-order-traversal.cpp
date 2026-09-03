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
    void levelOrder(TreeNode* root, vector<vector<int>> &result)
    {
        if(root == nullptr)
        return;
        queue<TreeNode*>q;
        q.push(root);

        int currLevel = 0;
        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> thisLevel;

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                thisLevel.push_back(current->val);

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            if(currLevel % 2 != 0)
            {
                reverse(thisLevel.begin(), thisLevel.end());
            }
            result.push_back(thisLevel);
            currLevel++; 
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root, result);
        return result;
    }
};