class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;
        for(int i : nums1)
        combined.push_back(i);

        for(int i : nums2)
        combined.push_back(i);

        sort(combined.begin(), combined.end());

        if(combined.size() % 2 != 0)
        return (double)combined[combined.size()/2];
        return ((double)(combined[(combined.size()-1)/2] + (double)combined[(combined.size()/2)])) / 2.0;
        
    }
};