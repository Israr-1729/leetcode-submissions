class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = nums.size();
        vector<int> result(size);
        int idx = 0;
        for(int i = 0; i<size/2; i++)
        {
            result[idx] = nums[i];
            idx++;
            result[idx] = nums[size/2 + i];
            idx++;
        }
        return result;
    }
};