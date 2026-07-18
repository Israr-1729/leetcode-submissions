class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minm = INT_MAX;
        int maxm = INT_MIN;

        for(int a : nums)
        {
            minm = min(a, minm);
            maxm = max(a, maxm);
        }
        return gcd(minm, maxm);
    }
};