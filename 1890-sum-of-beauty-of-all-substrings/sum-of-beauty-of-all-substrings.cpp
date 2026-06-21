class Solution {
public:

    int beautySubstr(string s)
    {
        vector<int>freq(26);
        for(char c : s)
        freq[c-'a']++;

        int minm = INT_MAX; int maxm = INT_MIN; 
        for(int i = 0; i<26; i++)
        {
            if(freq[i]>0)
            {
                minm = min(freq[i], minm);
                maxm = max(freq[i], maxm);
            }
        }
        return maxm-minm;
    }
    int beautySum(string s) {
        int size = s.size(); int ans = 0;
        for(int i = 0; i<size; i++)
        {
            for(int j = i; j<size; j++)
            {
                ans += beautySubstr(s.substr(i, j-i+1));
            }
        }
        return ans;
    }
};