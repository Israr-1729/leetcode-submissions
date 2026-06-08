class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int size = nums.size();
        vector<int> result(size);
        int idx = 0;
        for(int i = 0; i<size; i++)
        {
            if(nums[i]<pivot)
            result[idx++] = nums[i];
        }
        for(int i = 0; i<size; i++)
        {
            if(nums[i]==pivot)
            result[idx++] = nums[i];
        }
        for(int i = 0; i<size; i++)
        {
            if(nums[i]>pivot)
            result[idx++] = nums[i];
        }
        return result;
    }
};