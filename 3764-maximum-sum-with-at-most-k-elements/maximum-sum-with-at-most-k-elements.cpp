class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> nums;
        for(int i = 0; i < grid.size(); i++)
        {
            vector<int> &thisArr = grid[i];
            sort(thisArr.begin(), thisArr.end());
            int size = thisArr.size();
            for(int j = 0; j < limits[i] && size-j-1>=0; j++)
            {
                nums.push_back(thisArr[size-j-1]);
            }
        }

        sort(nums.begin(), nums.end());
        long long sum = 0;

        for(int i = 0; i < k && nums.size()-i-1>=0; i++)
        {
            sum += nums[nums.size()-i-1];
        }

        return sum;
    }
};