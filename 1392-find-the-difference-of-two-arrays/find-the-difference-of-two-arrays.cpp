class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> copy1;
        unordered_set<int> copy2;

        for(int a : nums1)
        {
            copy1.insert(a);
        }

        for(int b : nums2)
        {
            copy2.insert(b);
        }

         vector<int> ans1;
        for(auto &a : copy1)
        {
            if(!copy2.contains(a))
            ans1.push_back(a);
        }

        vector<int> ans2;
        for(auto &a : copy2)
        {
            if(!copy1.contains(a))
            ans2.push_back(a);
        }
        
        return {ans1, ans2};
    }
};