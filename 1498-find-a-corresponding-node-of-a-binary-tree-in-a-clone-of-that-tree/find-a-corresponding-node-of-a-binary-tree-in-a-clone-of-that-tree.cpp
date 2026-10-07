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
    bool isSame(TreeNode* thisOne, TreeNode* target)
    {
        if(thisOne == nullptr && target == nullptr)
        return true;

        if(thisOne == nullptr && target != nullptr)
        return false;

        if(thisOne != nullptr && target == nullptr)
        return false;

        if(thisOne -> val != target -> val)
        return false;

        return isSame(thisOne -> left, target -> left) && isSame(thisOne-> right, target->right);
    }
    void creator(TreeNode* cloned, TreeNode* target, TreeNode* &ans)
    {
        if(target == nullptr || cloned == nullptr)
        return;

        if(isSame(cloned, target))
        {
            ans = cloned;
            return;
        }

        creator(cloned->left, target, ans);
        creator(cloned->right, target, ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = new TreeNode(0);
        creator(cloned, target, ans);
        return ans;
    }
};