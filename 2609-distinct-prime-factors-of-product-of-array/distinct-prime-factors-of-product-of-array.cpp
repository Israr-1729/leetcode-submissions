class Solution {
public:

    vector<int> primeNumbers;

void fillPrimeNumbers()
{
    static bool isPrime[1001];

    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= 1000; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1000; j += i)
                isPrime[j] = false;
        }
    }

    primeNumbers.clear();
    primeNumbers.reserve(168);

    for (int i = 2; i <= 1000; ++i)
    {
        if (isPrime[i])
            primeNumbers.push_back(i);
    }
}

    int distinctPrimeFactors(vector<int>& nums) {
        fillPrimeNumbers();

        unordered_set<int> primeFactors;
        for(int a : nums)
        {
            for(int b : primeNumbers)
            {
                if(a % b == 0)
                primeFactors.insert(b);
            }
        }

        return primeFactors.size();
    }
};