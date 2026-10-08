class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> copy;
        for(int i : nums)
        {
            copy.insert(i);
        }

        int num = original;
        while(copy.contains(num))
        {
            num *= 2;
        }

        return num;
    }
};