class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> numsCopy;
        for(int a : nums)
        {
            numsCopy.insert(a);
        }

        int result = 0;
        for(int a : nums)
        {
            if(numsCopy.contains(a + diff) && numsCopy.contains(a + diff + diff))
            result++;
        }
        return result;
    }
};