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
    
    void fillArray(TreeNode* root, vector<vector<int>> &levelOrder)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> thisLevel;
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                thisLevel.push_back(current->val);

                if(current->left)
                q.push(current->left);

                if(current->right)
                q.push(current->right);
            }
            levelOrder.push_back(thisLevel);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> levelOrder;
        fillArray(root, levelOrder);
        const vector<int> &toAdd = levelOrder.back();
        int sum = 0;
        for(int i : toAdd)
        {
            sum += i;
        }
    return sum;
    }
};