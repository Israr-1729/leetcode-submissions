class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result(nums.size(), 0);
        int idx = 0;

        for(int i = 0; i < nums.size(); i+=2)
        {
            result[idx++] = nums[i+1];
            result[idx++] = nums[i];
        }
        return result;
    }
};