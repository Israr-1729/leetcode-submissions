class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        for(string &s : words1)
        {
            mp1[s]++;
        }

        for(string &s : words2)
        {
            mp2[s]++;
        }

        int result = 0;
        for(auto &a : mp1)
        {
            if(mp2.contains(a.first) && a.second == 1 && mp2[a.first]==1)
            result++;
        }
        return result;
    }
};