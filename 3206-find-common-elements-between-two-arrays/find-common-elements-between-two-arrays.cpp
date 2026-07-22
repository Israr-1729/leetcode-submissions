class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        int answer1 = 0; int answer2 = 0;
        unordered_set<int> nums1Copy;
        unordered_set<int> nums2Copy;

        for(int a : nums1)
        nums1Copy.insert(a);

        for(int a : nums2)
        nums2Copy.insert(a);

        for(int a : nums1)
        {
            if(nums2Copy.contains(a))
            answer1++;
        }

        for(int a : nums2)
        {
            if(nums1Copy.contains(a))
            answer2++;
        }
        
        return {answer1, answer2};
    }
};