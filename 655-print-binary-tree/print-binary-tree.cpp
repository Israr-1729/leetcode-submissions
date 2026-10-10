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
    long long change;
    int h(TreeNode* root)
    {
        if(root == nullptr)
        return 0;

        int height = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size() != 0)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* front = q.front();
                if(front->left)
                q.push(front->left);

                if(front->right)
                q.push(front->right);

                q.pop();
            }
            height++;
        }
        return height;
    }

    void fill(TreeNode* root, vector<vector<string>> &result)
    {
        if(root == nullptr)
        return;
        int column = result[0].size();
        int row = 0;
        result[row][(column-1)/2] = to_string(root->val);
        queue<pair<TreeNode*, int>> q;
        q.push({root, (column-1)/2});

        while(q.size() != 0)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* front = q.front().first;
                int c = q.front().second;
                if(front->left)
                {
                result[row+1][c-(change/(pow(2, row)))] = to_string(front->left->val);
                q.push({front->left, c-(change/(pow(2, row)))});
                }

                if(front->right)
                {
                result[row+1][c+(change/(pow(2, row)))] = to_string(front->right->val);
                q.push({front->right, c+(change/(pow(2, row)))});
                }

                q.pop();
            }
            row++;
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = h(root)-1;
        change = pow(2, height-1);
        cout<<height;
        vector<string> row; vector<vector<string>> result;
        for(int i = 0; i < pow(2, height+1)-1; i++)
        row.push_back("");

        for(int i = 0; i < height + 1; i++)
        result.push_back(row);

        fill(root, result);
        return result;
    }
};