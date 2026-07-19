class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1; unordered_set<int> s2;
        for(int a : nums1)
        s1.insert(a);

        for(int b : nums2)
        {
            if(s1.contains(b))
            s2.insert(b);
        }
        
        vector<int> result;
        for(auto &a : s2)
        {
            result.push_back(a);
        }
        return result;
    }
};