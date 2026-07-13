class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;

        long long refill = k;
        long long energy = k;
        long long nextCost = 1;
        long long cost = 0;

        for (int a : nums) {
            if (energy < a) {
                long long need = (a - energy + refill - 1) / refill;

                __int128 sum = (__int128)need * (2LL * nextCost + need - 1) / 2;

                cost = (cost + (long long)(sum % MOD)) % MOD;

                nextCost += need;
                energy += need * refill;
            }

            energy -= a;
        }

        return (int)cost;
    }
};