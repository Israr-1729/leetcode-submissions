class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26, 0);

        for(char c : s)
        {
            freq[c-'a']++;
        }

        int commonFreq = freq[s[0]-'a'];
        for(int a : freq)
        {
            if(a==0)
            continue;
            
            if(a!=commonFreq)
            return false;
        }
        return true;
    }
};