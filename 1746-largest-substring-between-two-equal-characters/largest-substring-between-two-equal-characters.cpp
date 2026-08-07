class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> freq;
        for(int i = 0; i < s.size(); i++)
        {
            freq[s[i]].push_back(i);
        }

        int longest = -1;
        for(auto &a : freq)
        {
            const vector<int> &thisRange = a.second;
            if(a.second.size() < 2)
            continue;

            else
            longest = max(longest, thisRange.back() - thisRange.front() - 1);
        }
        return longest;
    }
};