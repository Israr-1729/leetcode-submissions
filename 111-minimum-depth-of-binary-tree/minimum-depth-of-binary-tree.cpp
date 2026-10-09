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
    int minDepth(TreeNode* root) {
        int depth = 0;
        if(root == nullptr)
        return 0;

        queue<TreeNode*> q;
        q.push(root);

        while(q.size() != 0)
        {
            int size = q.size();
            bool leafFound = false;
            for(int i = 0; i < size; i++)
            {
                TreeNode* front = q.front();
                if(!front->left && !front->right)
                leafFound = true;

                if(front->left)
                q.push(front->left);

                if(front->right)
                q.push(front->right);

                q.pop();
            }
            depth++;
            if(leafFound)
            return depth;
        }
        return -1;
    }
};