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
    void level(TreeNode* root, int &ans)
    {
        if(root == nullptr)
        return;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(q.size() != 0)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* front = q.front().first;

                if(front->val >= q.front().second)
                {
                    cout<<front->val<<"\n";
                    ans++;
                }

                int maxSoFar = max(q.front().second, front->val);
                if(front->left)
                {
                    q.push({front->left, maxSoFar});
                }
                if(front->right)
                {
                    q.push({front->right, maxSoFar});
                }
                q.pop();
            }
        }
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        level(root, ans);
        return ans;
        
    }
};