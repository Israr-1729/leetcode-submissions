class Solution {
public:
    int smallest = INT_MAX;
    unordered_set<int> seen;
    bool isPrime(int n)
    {
        if(n == 2)
        return true;

        else if(n % 2 == 0 || n < 0)
        return false;

        for(int i = 3; i*i <= n; i++)
        {
            if(n%i == 0)
            return false;
        }
        return true;
    }
    int smallestValue(int n) {
        smallest = min(smallest, n);

        if(seen.contains(n))
        return smallest;

        seen.insert(n);
        vector<int> primeFactors;
        for(int i = 2; i<=n; i++)
        {
            if(!isPrime(i))
            continue;

            while(n % i == 0)
            {
                primeFactors.push_back(i);
                n/=i;
            }

            if(n == 1)
            break;
        }

        int sum = 0;
        for(int i : primeFactors)
        {
            sum += i;
        }

        return smallestValue(sum);
    }
};