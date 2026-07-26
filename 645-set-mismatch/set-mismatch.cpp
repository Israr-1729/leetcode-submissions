class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> copy;
        int size = nums.size();
        for(int a : nums)
        {
            copy[a]++;
        }

        int missing = size; int repeat = size;
        for(int i = 1; i<=size; i++)
        {
            if(copy[i]==0)
            missing = i;

            if(copy[i]==2)
            repeat = i;
        }
        return {repeat, missing};
    }
};