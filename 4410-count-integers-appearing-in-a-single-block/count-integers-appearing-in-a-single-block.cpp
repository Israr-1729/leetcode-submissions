class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> special;
        unordered_set<int> skip;
        int i = 0; int size = nums.size();
        while(i < size)
        {
            if(skip.contains(nums[i]))
            {
                i++;
                continue;
            }

            if(special.contains(nums[i]))
            {
                special.erase(nums[i]);
                skip.insert(nums[i]);
                i++;
                continue;
            }

            else
            special.insert(nums[i]);

            int toCheck = nums[i];
            while(i < size && nums[i] == toCheck)
            {
                i++;
            }
        }
        return special.size();
    }
};