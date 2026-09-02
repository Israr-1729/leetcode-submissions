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
    void levelOrder(TreeNode* root, vector<long long> &levelToSum, unordered_map<TreeNode*, int> &mp)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);
        mp[root] = 0;
        while(!q.empty())
        {
            int levelSize = q.size();
            long long sum = 0;
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();
                sum += current->val;

                if(current->left)
                {
                    q.push(current->left);


                    if(current->right)
                    {
                        mp[current->left] = current->right->val;
                    }

                    else
                    {
                        mp[current->right] = 0;
                    }
                }

                if(current->right)
                {
                    q.push(current->right);

                    if(current->left)
                    {
                        mp[current->right] = current->left->val;
                    }

                    else
                    {
                        mp[current->right] = 0;
                    }
                }
            }
            levelToSum.push_back(sum);
        }    
    }

    void update(TreeNode* root, unordered_map<TreeNode*, int> &mp, const vector<long long> &sums)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);

        int currentLevel = 0;

        while(!q.empty())
        {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                current->val = sums[currentLevel] - mp[current] - current->val;

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            currentLevel++;
        }
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        vector<long long> levelToSums;

        levelOrder(root, levelToSums, mp);
        update(root, mp, levelToSums);

        return root;
        
    }
};