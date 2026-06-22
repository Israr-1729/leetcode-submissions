class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int a : nums)
        {
            mp[a]++;
        }

        for(int a : nums)
        {
            if(a%2==0 && mp[a]==1)
            return a;
        }
        return -1;
    }
};