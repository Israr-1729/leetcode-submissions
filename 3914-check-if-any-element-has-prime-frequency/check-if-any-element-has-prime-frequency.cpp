class Solution {
public:

    bool isPrime(int n)
    {
        if(n==2)
        return true;

        if(n<2 || n%2==0)
        return false;

        for(int i = 3; i*i<=n; i+=2)
        {
            if(n%i==0)
            return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int a : nums)
        {
            freq[a]++;
        }

        for(auto &p : freq)
        {
            if(isPrime(p.second))
            return true;
        }
       return false; 
    }
};