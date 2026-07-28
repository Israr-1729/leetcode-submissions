class Solution {
private:

    struct FreqChart
    {
        int size;
        vector<int> freqArr;
        bool isOdd;
        char Odd;
    };

public:
    string makePairs(const FreqChart &fc)
    {
        string result = "";
        result.resize(fc.size);

        int firstPointer = 0;
        int lastPointer = fc.size-1;

        const vector<int> &freq = fc.freqArr;

        for(int i = 0; i<26; i++)
        {
            if(freq[i] != 0)
            {
                for(int j = 0; j<freq[i]/2; j++)
                {
                    result[firstPointer++] = 'a' + i;
                    result[lastPointer--] = 'a' + i;
                }
            }
        }

        if(!fc.isOdd)
        return result;

        else
        {
            result[(fc.size-1)/2] = fc.Odd;
            return result;
        }
    }

    FreqChart freqCharter(const string &s)
    {
        FreqChart result;
        vector<int> freq(26, 0);
        bool containsOdd = false;
        char Oddchar = 0;
        int stringSize = s.size();

        for(char c : s)
        {
            freq[c-'a']++;
        }

        for(int i = 0; i<26; i++)
        {
            if(freq[i]%2 == 1)
            {
                containsOdd = true;
                Oddchar = 'a' + i;
                break;
            }
        }

        result.freqArr = freq;
        result.isOdd = containsOdd;
        result.Odd = Oddchar;
        result.size = stringSize;

        return result; 
    }

    string smallestPalindrome(string s) {
        FreqChart freqChart = freqCharter(s);
        return makePairs(freqChart);
    }
};