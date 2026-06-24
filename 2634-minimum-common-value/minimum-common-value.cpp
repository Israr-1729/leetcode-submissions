class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> copy1;
        for(int a : nums1)
        copy1.insert(a);

        int smallestNum = INT_MAX;
        bool commonFound = false;
        for(int a : nums2)
        {
            if(copy1.find(a)!=copy1.end())
            {
            smallestNum = min(a, smallestNum);
            commonFound = true;
            }
        }
        return commonFound ? smallestNum : -1;
    }
};