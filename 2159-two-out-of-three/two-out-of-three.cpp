class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, unordered_set<int>> freq;
        for(int i : nums1)
        {
            freq[i].insert(1);
        }

        for(int i : nums2)
        {
            freq[i].insert(2);
        }

        for(int i : nums3)
        {
            freq[i].insert(3);
        }
        
        vector<int> result;
        for(auto &a : freq)
        {
            if(a.second.size() >= 2)
            result.push_back(a.first);
        }

        return result;
    }
};