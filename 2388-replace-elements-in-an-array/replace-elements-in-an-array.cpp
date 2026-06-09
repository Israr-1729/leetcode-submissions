class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> m;

        // Process operations in reverse
        for (int i = operations.size() - 1; i >= 0; i--) {
            int oldVal = operations[i][0];
            int newVal = operations[i][1];

            // If newVal already changes further, inherit final value
            if (m.find(newVal) != m.end())
                m[oldVal] = m[newVal];
            else
                m[oldVal] = newVal;
        }

        // Update nums
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end())
                nums[i] = m[nums[i]];
        }

        return nums;
    }
};