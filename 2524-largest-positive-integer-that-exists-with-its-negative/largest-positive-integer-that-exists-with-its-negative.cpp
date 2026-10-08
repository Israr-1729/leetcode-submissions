class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> copy;
        for(int i : nums)
        {
            copy.insert(i);
        }

        int largest = -1;
        for(int i : nums)
        {
            if(i > 0 && i > largest && copy.contains(i * -1))
            largest = i;
        }
        return largest;
    }
};