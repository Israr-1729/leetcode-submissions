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

    bool compare(TreeNode* p, TreeNode* q)
    {
        if(p==nullptr || q == nullptr)
        {
            return p == q;
        }

        bool isLeftSame = compare(p->left, q->left);
        bool isRightSame = compare(p->right, q->right);

        return isLeftSame && isRightSame && p->val == q->val;
    }

    bool ans = false;
void traverse(TreeNode* root, TreeNode* subRoot)
{
    if(root == nullptr || ans)
        return;

    if(compare(root, subRoot))
    {
        ans = true;
        return;
    }

    traverse(root->left, subRoot);
    traverse(root->right, subRoot);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        traverse(root, subRoot);
        return ans;
    }
};