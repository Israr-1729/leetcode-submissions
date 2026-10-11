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
 struct modifiedNode 
 {
    TreeNode* T;
    vector<int> values;
    long long sumSoFar = 0;
 };

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if(root == nullptr)
        return {};

        modifiedNode* newNode = new modifiedNode;
        newNode->T = root;
        newNode->values = {root->val};
        newNode->sumSoFar = root->val;
        queue<modifiedNode*> q;
        q.push(newNode);

        while(q.size() != 0)
        {
            modifiedNode* front = q.front();

            if(!front->T->left && !front->T->right)
            {
                cout<<front->sumSoFar<<"\n";
                if(front->sumSoFar == targetSum)
                result.push_back(front->values);
            }

            if(front->T->left)
            {
                vector<int> valuesSoFar = front->values;

                modifiedNode* toAdd = new modifiedNode;
                toAdd->T = front->T->left;
                valuesSoFar.push_back(front->T->left->val);
               
                toAdd->values = valuesSoFar;
                toAdd->sumSoFar = front->sumSoFar + valuesSoFar.back();
                q.push(toAdd);
            }

            if(front->T->right)
            {
                vector<int> valuesSoFar = front->values;

                modifiedNode* toAdd = new modifiedNode;
                toAdd->T = front->T->right;
                valuesSoFar.push_back(front->T->right->val);
               
                toAdd->values = valuesSoFar;
                toAdd->sumSoFar = front->sumSoFar + valuesSoFar.back();
                q.push(toAdd);
            }

            q.pop();
        }
        return result;
    }
};