class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for(string &p : words)
        {
            if(s.starts_with(p))
            count++;
        }
        return count;
    }
};