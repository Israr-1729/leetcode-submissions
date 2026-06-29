class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> validPairs;

        int maxDistance = 0;
        int size1 = nums1.size(); int size2 = nums2.size();
        int i = 0; int j = 0;

        while(i<size1 && j<size2)
        {
            while(j<size2 && i<size1 && nums1[i]<=nums2[j])
            {
                maxDistance = max(maxDistance, j-i);
                j++;
            }

            while(i<size1 && j<size2 && nums1[i]<=nums2[j])
            {
                maxDistance = max(maxDistance, j-i);
                i++;
            }
            i++; j++;
        }
        return maxDistance;
    }
};