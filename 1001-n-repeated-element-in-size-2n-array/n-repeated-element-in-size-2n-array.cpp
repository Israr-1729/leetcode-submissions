class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> contains;
        for(int a : nums)
        {
            if(contains.contains(a))
            return a;

            contains.insert(a);
        }
        return -1;
    }
};