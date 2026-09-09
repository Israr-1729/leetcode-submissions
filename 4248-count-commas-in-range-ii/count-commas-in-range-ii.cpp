class Solution {
public:
    long long minm(long long a, long long b)
    {
        return (a < b ? a : b);
    }
    long long countCommas(long long n) {
        long long ans = 0;
        if(n >= 1e3)
        ans += (minm(n, 1e6-1) - 1000 + 1) * 1;

        if(n >= 1e6)
        ans += (minm(n, 1e9-1) - 1e6 + 1) * 2;

        if(n >= 1e9)
        ans += (minm(n, 1e12-1) - 1e9 + 1) * 3;

        if(n >= 1e12)
        ans += (minm(n, 1e15-1) - 1e12 + 1) * 4;

        if (n == 1e15)
        ans += 5;
        
        return ans;
    }
};