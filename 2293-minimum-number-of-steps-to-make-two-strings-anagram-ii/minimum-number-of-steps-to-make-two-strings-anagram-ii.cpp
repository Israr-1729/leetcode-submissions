class Solution {
public:
    vector<int> freqParser(const string &s)
    {
        vector<int> result(26, 0);
        for (char c : s)
        {
            result[c-'a']++;
        }
        return result;
    }

    int minSteps(string s, string t) {
        vector<int> sCopy = freqParser(s);
        vector<int> tCopy = freqParser(t);

        int ans = 0;

        for(int i = 0; i<26; i++)
        {
            ans += abs(sCopy[i] - tCopy[i]);
        }

        return ans;
        
    }
};