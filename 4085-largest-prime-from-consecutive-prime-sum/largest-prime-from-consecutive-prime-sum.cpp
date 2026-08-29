class Solution {
public:
    unordered_set<int> primeNumbersSum;

    vector<bool> prime;

void sieve(int n)
{
    prime.assign(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}

bool isPrime(int x)
{
    return prime[x];
}

    void fillPrimeNumbers()
    {
        int runningSum = 0;
        for(int i = 1; i <= 50000; i++)
        {
            if(isPrime(i))
            {
                runningSum += i;
                primeNumbersSum.insert(runningSum);
            }

            if(runningSum >= 500000)
            break;
        }
    }

    int largestPrime(int n) {
        sieve(500000);
        fillPrimeNumbers();
        while(n >= 0)
        {
            if(primeNumbersSum.contains(n) && isPrime(n))
            return n;
            n--;
        }
        return 0;
    }
};