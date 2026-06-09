class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            int copy = i+1;
            while(copy<size && (copy-i<=k))
            {
                if(nums[i]==nums[copy])
                return true;
                copy++;
            }
        }
        return false;
    }
};