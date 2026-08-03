class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int size = nums.size();
        long long strength;
        long long maxStrength = INT_MIN;
        for(int a : nums)
        {
            for(int b : nums)
            {
                long long d = gcd(a, b);
                strength = (1LL*a*b)/(1LL*d*d);
                maxStrength = max(strength, maxStrength);
            }
        }
        return maxStrength;
    }
};