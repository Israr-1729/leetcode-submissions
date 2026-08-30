class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        for(auto &r : matrix)
        {
            for(int i : r)
            {
                nums.push_back(i);
            }
        }
        
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};