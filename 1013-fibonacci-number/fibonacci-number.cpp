class Solution {
public:
    int fib(int n) {
        if(n<=1)
        return n;
        vector<long long> lastTwo(2);
        lastTwo[0] = 0;
        lastTwo[1] = 1;
        for(int i = 2; i<=n; i++)
        {
            int temp = lastTwo[0];
            lastTwo[0] = lastTwo[1];
            lastTwo[1] = temp + lastTwo[0];
        }
        return lastTwo[1];
    }
};