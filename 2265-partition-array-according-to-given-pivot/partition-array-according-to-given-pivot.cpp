class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int size = nums.size();
        vector<int> smaller;
        vector<int> larger;
        vector<int> equal;
        for(int i = 0; i<size; i++)
        {
            if(nums[i]<pivot)
            smaller.push_back(nums[i]);
            else if(nums[i]>pivot)
            larger.push_back(nums[i]);
            else
            equal.push_back(nums[i]);
        }

        vector<int> result(size);
        int idx = 0;
        for(int i = 0; i<smaller.size(); i++)
        {
            result[idx++] = smaller[i];
        }
        for(int i = 0; i<equal.size(); i++)
        {
            result[idx++] = equal[i];
        }
        for(int i = 0; i<larger.size(); i++)
        {
            result[idx++] = larger[i];
        }
        return result;
    }
};