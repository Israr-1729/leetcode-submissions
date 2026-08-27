class Solution {
public:

    vector<long long> perfectSquares;

    bool isPrime(int n)
    {
        if(n < 2)
            return false;

        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
                return false;
        }

        return true;
    }

    void fillPerfectSquares()
    {
        int i = 2;

        while(1LL * i * i <= 1e9)
        {
            if(isPrime(i))
                perfectSquares.push_back(1LL * i * i);

            i++;
        }
    }

    int nonSpecialCount(int l, int r) {
        fillPerfectSquares();

        int special = 0;

        for(long long x : perfectSquares)
        {
            if(x >= l && x <= r)
                special++;
        }

        return (r - l + 1) - special;
    }
};