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
    unordered_map<TreeNode*, string> locations;
    void levelOrder(TreeNode* original, TreeNode* &target, string &ans)
    {
        if(original == nullptr)
        return;

        string begin = "";
        queue<TreeNode*> q;
        q.push(original);
        locations[original] = "";
        
        while(q.size() != 0)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                if(q.front() == target)
                {
                    ans = locations[q.front()];
                }
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                    locations[q.front()->left] = locations[q.front()] + "L";
                }

                if(q.front() -> right)
                {
                    q.push(q.front()->right);
                    locations[q.front()->right] = locations[q.front()] + "R";
                }

                q.pop();
            }
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        string ans;
        levelOrder(original, target, ans);

        if(ans == "")
        return cloned;

        TreeNode* travel = cloned;
        for(char c : ans)
        {
            if(c == 'L')
            travel = travel->left;

            else
            travel = travel->right;
        }

        return travel;
    }
};