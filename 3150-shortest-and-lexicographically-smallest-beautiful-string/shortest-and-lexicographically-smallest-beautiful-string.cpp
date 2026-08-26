class Solution {
public:

    int onesCount(const string &s)
    {
        int ones = 0;
        for(char c : s)
        {
            if(c=='1')
            ones++;
        }
        return ones;
    }

    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<int, set<string>> beautiful;
        for(int i = 0; i < s.size(); i++)
        {
            int onesCount = 0;
            for(int j = i; j < s.size(); j++)
            {
                if(s[j] == '1')
                onesCount++;

                if(onesCount == k)
                {
                    beautiful[j-i+1].insert(s.substr(i, j-i+1));
                    break;
                }
            }       
        }

        if(beautiful.empty())
        return "";

        int smallest = INT_MAX;
        for(auto &a : beautiful)
        {
            smallest = min(smallest, a.first);
        }

        const set<string> result = beautiful[smallest];
        string ans = *result.begin();



        return ans;
    }
};