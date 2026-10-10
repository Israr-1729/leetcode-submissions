class Solution {
public:
    bool findPath(TreeNode* node, int target, string &path) {
        if (!node) return false;
        if (node->val == target) return true;

        path.push_back('L');
        if (findPath(node->left, target, path)) return true;
        path.back() = 'R';
        if (findPath(node->right, target, path)) return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s, d;
        findPath(root, startValue, s);
        findPath(root, destValue, d);

        int i = 0;
        while (i < s.size() && i < d.size() && s[i] == d[i]) i++;

        return string(s.size() - i, 'U') + d.substr(i);
    }
};