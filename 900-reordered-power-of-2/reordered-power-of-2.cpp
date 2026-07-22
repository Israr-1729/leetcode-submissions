class Solution {
public:

    vector<long long> powers;

    string toString(long long a)
    {
        string result = "";
        while(a)
        {
            result.push_back(a%10);
            a/=10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    bool isAnagram(long long a, long long b)
    {
        vector<int> aDigits(10);
        vector<int> bDigits(10);

        while(a)
        {
            int digit = a%10;
            aDigits[digit]++;
            a/=10;
        }

        while(b)
        {
            int digit = b%10;
            bDigits[digit]++;
            b/=10;
        }

        for(int i = 0; i<10; i++)
        {
            if(aDigits[i]!=bDigits[i])
            return false;
        }
        return true;

    }
    void generator()
    {
        long long i = 1;
        while(i<1LL*INT_MAX*10)
        {
            powers.push_back(i);
            i *= 2;
        }
    }

    bool reorderedPowerOf2(int n) {

        generator();
        int size = toString(n).size();
        for(long long a : powers)
        {
            if(toString(a).size() != size)
            continue;

            else
            {
                if(isAnagram(a, n))
                return true;
            }
        }
        return false;
    }
};