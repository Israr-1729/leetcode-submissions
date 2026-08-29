class Solution {
public:
    unordered_set<int> primeNumbersSum;
    unordered_set<int> primes;

    bool isPrime(int n)
    {
        if(n == 2)
        return true;

        if(n < 2 || n%2 == 0)
        return false;

        for(int i = 3; i * i <= n; i += 2)
        {
            if(n % i == 0)
            return false;
        }

        return true;
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
                primes.insert(i);
            }

            if(runningSum >= 500000)
            break;
        }
    }

    int largestPrime(int n) {
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