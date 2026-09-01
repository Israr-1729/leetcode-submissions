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
class FindElements {
public:
    unordered_set<int> isPresent;

    void traverse(TreeNode* root)
    {
        if(root == nullptr)
        return;

        if(root->left)
        {
            root->left->val = 2*root->val + 1;
            isPresent.insert(root->left->val);
        }

        if(root->right)
        {
            root->right->val = 2*root->val + 2;
            isPresent.insert(root->right->val);
        }

        traverse(root->left);
        traverse(root->right);
    }
    FindElements(TreeNode* root) {
        isPresent.insert(0);
        root->val = 0;
        traverse(root);
    }
    
    bool find(int target) {
        return isPresent.contains(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */