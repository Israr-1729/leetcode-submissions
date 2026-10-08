class Solution {

public : 
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (original == target)
        return cloned;

    if (original->left) {
        TreeNode* ans = getTargetCopy(original->left, cloned->left, target);
        if (ans)
            return ans;
    }

    if (original->right) {
        TreeNode* ans = getTargetCopy(original->right, cloned->right, target);
        if (ans)
            return ans;
    }

    return nullptr;
}
};