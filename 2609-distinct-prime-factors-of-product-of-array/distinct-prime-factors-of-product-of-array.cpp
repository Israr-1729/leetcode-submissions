class Solution {
public:

    vector<int> primeNumbers;

    bool isPrime (int num) {
        if(num == 2)
        return true;

        if(num < 2 || num % 2 == 0)
        return false;

        for(int i = 3; i*i <= num; i+=2) {
            if(num % i == 0)
            return false;
        }
        return true;
    }

    void fillPrimeNumbers() {
        for(int i = 2; i <= 1000; i++)
        {
            if(isPrime(i))
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