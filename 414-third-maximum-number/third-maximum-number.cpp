class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> noDuplicates;
        int i = 0;
        int size = nums.size();
        while(i<size)
        {
            noDuplicates.push_back(nums[i]);
            i++;
            while(i<size && nums[i]==nums[i-1])
            i++;
        }

        int size2 = noDuplicates.size();
        if(size2<3)
        return noDuplicates[size2-1];
        return noDuplicates[size2-3];
        
    }
};