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
    TreeNode* nullRemover()
    {
        TreeNode* newNode = new TreeNode(INT_MIN);
        return newNode;
    }

    bool isLevelSymmetric(vector<int> &thisLevel)
    {
        if(thisLevel.size() == 1)
        return true;

        if(thisLevel.size() %2 != 0)
        return false;

        int begin = 0;
        int end = thisLevel.size()-1;

        while(begin <= end)
        {
            if(thisLevel[begin] != thisLevel[end])
            return false;

            begin++;
            end--;
        }

        return true;
    }

    bool levelOrder(TreeNode* root)
    {
        if(root == nullptr)
        return true;

        queue<TreeNode*> q;
        q.push(root);

        while(q.size() != 0)
        {
            vector<int> thisLevel;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* top = q.front();
                thisLevel.push_back(top->val);

                if(top->val != INT_MIN && !top->left)
                top->left = nullRemover();

                if(top->val != INT_MIN && !top->right)
                top->right = nullRemover();

                if(top->left)
                q.push(top->left);
                if(top->right)
                q.push(top->right);

                q.pop();
            }
            if(!isLevelSymmetric(thisLevel))
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return levelOrder(root);
    }
};