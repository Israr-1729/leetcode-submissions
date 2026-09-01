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
    void levelOrder(TreeNode* &root, vector<vector<int>> &result)
    {
        if(root == nullptr)
        {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> thisLevel;
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                thisLevel.push_back(current->val);

                if(current->left)
                {
                    q.push(current->left);
                }

                if(current->right)
                {
                    q.push(current->right);
                }
            }
            result.push_back(thisLevel);
        }

        for(int i = 1; i <result.size(); i+=2)
        {
            reverse(result[i].begin(), result[i].end());
        }
    }

    vector<int> atomizer(const vector<vector<int>> &toReplace)
    {
        vector<int> result;
        for(auto &a : toReplace)
        {
            for(int i : a)
            result.push_back(i);
        }
        return result;
    }

    void replace(TreeNode* &root, const vector<int> &toReplace)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);

        int idx = 0;

        while(!q.empty())
        {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                current->val = toReplace[idx++];

                if(current->left)
                {
                    q.push(current->left);
                }

                if(current->right)
                {
                    q.push(current->right);
                }
            }
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> toReplace;
        levelOrder(root, toReplace);
        replace(root, atomizer(toReplace));
        return root;
    }
};