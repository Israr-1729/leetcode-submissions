class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> copy;
        for(int i : nums)
        {
            copy.insert(i);
        }

        for(int i = k; i >= 0; i += k)
        {
            if(!copy.contains(i))
            return i;
        }

        return -1;
        
    }
};