class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> copy;
        for(int a : nums)
        copy.insert(a);

        vector<int> sorted;
        for(auto &a : copy)
        sorted.push_back(a);

        if(sorted.size()<3)
        return sorted[sorted.size()-1];

        else
        return sorted[sorted.size()-3];
    }
};