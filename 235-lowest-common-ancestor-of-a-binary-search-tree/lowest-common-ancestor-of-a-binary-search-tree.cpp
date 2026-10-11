/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void ancestor(TreeNode* root, int startNum, int endNum, vector<int> &start, vector<int> &end)
    {
        queue<pair<TreeNode*, vector<int>>> q;
        q.push({root, {}});

        while(q.size() != 0)
        {
            bool startFound = false;
            bool endFound = false;
            TreeNode* front = q.front().first;
            q.front().second.push_back(front->val);

            if(front->val == startNum)
            {
                startFound = true;
                start = q.front().second;
            }

            if(front->val == endNum)
            {
                endFound = true;
                end = q.front().second;
            }

            if(startFound && endFound)
            return;

            if(front->left)
            {
                q.push({front->left, q.front().second});
            }

            if(front->right)
            {
                q.push({front->right, q.front().second});
            }

            q.pop();
        }
    }

    TreeNode* lowest(TreeNode* root, vector<int> &startAncestor, vector<int> &endAncestor)
    {
        unordered_set<int>endCopy;
        for(int i : endAncestor)
        {
            endCopy.insert(i);
        }

        int value;
        for(int i = startAncestor.size()-1; i>=0; i--)
        {
            if(endCopy.contains(startAncestor[i]))
            {
                value = startAncestor[i];
                break;
            }
        }

        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() != 0)
        {
            TreeNode* front = q.front();
            if(front->val == value)
            return front;

            if(front->left)
            q.push(front->left);

            if(front->right)
            q.push(front->right);

            q.pop();
        }

    return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> startAncestor;
        vector<int> endAncestor;

        ancestor(root, p->val, q->val, startAncestor, endAncestor);

        return lowest(root, startAncestor, endAncestor);
    }
};