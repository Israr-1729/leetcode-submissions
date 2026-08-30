class Solution {
public:
    bool isPrime(int n)
    {
        if(n == 2)
        return true;

        if(n % 2 == 0 || n < 2)
        return false;

        for(int i = 3; i * i <= n; i+=2)
        {
            if(n % i == 0)
            return false;
        }
        return true;
    }

    vector<int> factorize(int n)
    {
        vector<int> result;
        for(int i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                result.push_back(i);
                result.push_back(n/i);
            }
        }
        return result;
    }


    bool repeated(const string &toAdd, int times, const string &toCheck)
    {
        string result = "";
        for(int i = 0; i < times; i++)
        {
            result += toAdd;
            if(toCheck.find(result) != 0)
            return false;
        }
        return true;
    }

    bool repeatedSubstringPattern(string s) {

        vector<int> factors = factorize(s.size());
        for(int i : factors)
        {
            if(i == s.size())
            continue;

            if(repeated(s.substr(0, i), s.size()/i, s))
            return true;
        }
    return false;
    }
};