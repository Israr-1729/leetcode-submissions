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
    vector<int> vec(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;

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

                result.push_back(front->val);
                q.pop();
            }
        }
        sort(result.begin(), result.end());
        return result;
    }

    TreeNode* treeCreator(vector<int> nums)
    {
        TreeNode* dummyHead = new TreeNode(0);
        TreeNode* temp = dummyHead;

        for(int i = 0; i < nums.size(); i++)
        {
            TreeNode* newNode = new TreeNode(nums[i]);
            temp -> right = newNode;
            temp = temp->right;
        }
        
        return dummyHead->right;
    }
    TreeNode* increasingBST(TreeNode* root) {
        return treeCreator(vec(root));
    }
};