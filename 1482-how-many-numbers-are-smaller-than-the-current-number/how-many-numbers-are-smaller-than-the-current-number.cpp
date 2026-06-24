class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        multiset<int> copy;
        for(int a : nums)
        copy.insert(a);

        int size = nums.size();
        vector<int> result(size);

        for(int i = 0; i<size; i++)
        {
            int num = nums[i];
            int thisResult = 0;
            for(auto &a : copy)
            {
                if(a<num)
                thisResult++;
            }
            result[i] = thisResult;
        }
    return result;
    }
};