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

int minSwaps(const vector<int> &nums)
{
    int n = nums.size();

    vector<pair<int, int>> arr;

    for(int i = 0; i < n; i++)
    {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    vector<bool> visited(n, false);

    int swaps = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] || arr[i].second == i)
            continue;

        int cycleSize = 0;
        int j = i;

        while(!visited[j])
        {
            visited[j] = true;

            j = arr[j].second;

            cycleSize++;
        }

        swaps += cycleSize - 1;
    }

    return swaps;
}
    void calculator(TreeNode* root, int &ans)
    {
        if(root == nullptr)
        return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {

            int levelSize = q.size();
            vector<int> thisLevel;
            
            for(int i = 0; i < levelSize; i++)
            {

                TreeNode* current = q.front();
                q.pop();

                thisLevel.push_back(current->val);
                if(current->left)
                {
                    q.push(current->left);
                }

                if(current->right)
                {
                    q.push(current->right);
                }
            }
            ans += minSwaps(thisLevel);
        }
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        calculator(root, ans);
        return ans;

        
    }
};