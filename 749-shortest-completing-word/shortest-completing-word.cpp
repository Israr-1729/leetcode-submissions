class Solution {
public:

    bool isSubset(vector<int> &lpf, vector<int> wordF)
    {
        for(int i = 0; i<26; i++)
        {
            if(wordF[i]<lpf[i])
            return false;
        }
        return true;
    }

    vector<int> freq(string &word)
    {
        vector<int> result(26,0);
        for(char c : word)
        {
            if(isalpha(c))
            result[tolower(c)-'a']++;
        }
        return result;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> LPF = freq(licensePlate);
        string ans = "";

        for(string &s : words)
        {
            if(isSubset(LPF, freq(s)))
            {
                if(ans == "")
                ans = s;

                if(ans.size()>s.size())
                ans = s;
            }
        }
        return ans;
    }
};