class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minimumOdd = INT_MAX;

        for (int x : nums1) {
            if (x & 1)
                minimumOdd = min(minimumOdd, x);
        }

        if (minimumOdd == INT_MAX)
            return true;

        for (int x : nums1) {
            if ((x & 1) == 0 && x < minimumOdd)
                return false;
        }

        return true;
    }
};