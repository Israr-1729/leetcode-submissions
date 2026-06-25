class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int>mp; int size = nums.size();
        for(int i = 0; i<size-1; i++)
        {
            if(nums[i]==key)
            mp[nums[i+1]]++;
        }

        int maximumFrequency = INT_MIN; int mostFrequent;
        for(auto &p : mp)
        {
            if(p.second>maximumFrequency)
            {
                mostFrequent = p.first;
                maximumFrequency = p.second;
            }
        }
        return mostFrequent;
    }
};