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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, int> sisters;
        unordered_map<int, int> nodeToLevel;
        int level = 0;

        if(root == nullptr)
        return false;

        queue<TreeNode*> q;
        q.push(root);
        nodeToLevel[root->val] = level++;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* thisNode = q.front();
                nodeToLevel[thisNode->val] = level;

                if(thisNode->left && thisNode->right)
                {
                    sisters[thisNode->left->val] = thisNode->right->val;
                    sisters[thisNode->right->val] = thisNode->left->val;
                }

                if(thisNode->left)
                {
                    q.push(thisNode->left);
                }

                if(thisNode->right)
                {
                    q.push(thisNode->right);
                }
                
                q.pop();
            }
            level++;
        }
        return nodeToLevel[x] == nodeToLevel[y] && sisters[x] != y;
    }
};