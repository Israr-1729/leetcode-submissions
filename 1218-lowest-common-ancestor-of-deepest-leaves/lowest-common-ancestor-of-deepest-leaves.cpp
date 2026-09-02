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


    void fillSet(TreeNode* root, unordered_set<TreeNode*> &thisSet)
    {
        if(root == nullptr)
        return;

        thisSet.insert(root);
        fillSet(root->left, thisSet);
        fillSet(root->right, thisSet);
    }

    void fillMap(TreeNode* root, unordered_map<TreeNode*, unordered_set<TreeNode*>> &mp)
    {
        if(root == nullptr)
        return;

        unordered_set<TreeNode*> thisNode;
        fillSet(root, thisNode);
        mp[root] = thisNode;

        fillMap(root->left, mp);
        fillMap(root->right, mp);
    }

    void levelOrder(TreeNode* root, vector<vector<TreeNode*>> &nodes)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();
            vector<TreeNode*> thisLevel;

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                thisLevel.push_back(current);
                
                if(current->left)
                q.push(current->left);

                if(current->right)
                q.push(current->right);
            }

            nodes.push_back(thisLevel);
        }
    }

TreeNode* subtree(TreeNode* root, TreeNode* toFind)
{
    if(root == nullptr)
        return nullptr;

    if(root == toFind)
        return root;

    TreeNode* result = subtree(root->left, toFind);

    if(result)
        return result;

    return subtree(root->right, toFind);
}

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, unordered_set<TreeNode*>> mappings;
        vector<vector<TreeNode*>> nodes;

        fillMap(root, mappings);
        levelOrder(root, nodes);

        const vector<TreeNode*> &lastLevel = nodes.back();
        TreeNode* ans = root;
        for(auto &a : mappings)
        {
            bool isTrue = true;
            const unordered_set<TreeNode*> &check = a.second;
            for(auto &t : lastLevel)
            {
                if(!check.contains(t))
                {
                    isTrue = false;
                    break;
                }
            }
            if(isTrue && a.second.size() < mappings[ans].size())
            {
                ans = a.first;
            }
        }

        return subtree(root, ans);
    }
};