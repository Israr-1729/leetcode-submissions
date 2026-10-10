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
    unordered_map<int, long long> toAdd;
    vector<int> values(TreeNode* root)
    {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size() != 0)
        {
            TreeNode* front = q.front();
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);

            result.push_back(front->val);
            q.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }

    void fillToAdd(vector<int> values)
    {
        long long runningSum = 0;
        for(int i = values.size()-1; i>=0; i--)
        {
            toAdd[values[i]] = runningSum;
            runningSum += values[i];
        }
    }

    void update(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0)
        {
            TreeNode* front = q.front();
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);

            front->val += toAdd[front->val];
            q.pop();
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr)
        return nullptr;
        fillToAdd(values(root));
        update(root);
        return root;
    }
};