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
    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        queue<pair<TreeNode*, string>> q;
        string start = ""; start += (root->val + 'a');
        q.push({root, start});

        while(q.size() != 0)
        {
            TreeNode* front = q.front().first;
            if(!front->left && !front->right)
            {
                string wholeString = q.front().second;
                reverse(wholeString.begin(), wholeString.end());

                if(result == "")
                result = wholeString;

                else
                result = min(wholeString, result);
            }

            if(front->left)
            q.push({front->left, q.front().second + (char)(front->left->val+'a')});

            if(front->right)
            q.push({front->right, q.front().second + (char)(front->right->val+'a')});

            q.pop();
        }
        return result;
    }
};