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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == nullptr)
        return {0};

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            double levelSum = 0;

            for(int i = 0; i < size; i++)
            {
                TreeNode* &thisNode = q.front();
                if(thisNode->left) q.push(thisNode->left);
                if(thisNode->right) q.push(thisNode->right);

                levelSum += thisNode->val; 
                q.pop();
            }
            result.push_back(levelSum / size);
        }
        return result;
    }
};