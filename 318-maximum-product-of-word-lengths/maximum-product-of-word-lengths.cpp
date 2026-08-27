class Solution {
public:
    unordered_set<char> letters(const string &word)
    {
        unordered_set<char> ans;
        for(char c : word)
        {
            ans.insert(c);
        }
        return ans;
    }

    bool exclusive(const string &s1, const unordered_set<char> &s2)
    {
        for(char c : s1)
        {
            if(s2.contains(c))
            return false;
        }
        return true;
    }

    int maxProduct(vector<string>& words) {
        int currMax = 0;
        for(int i = 0; i < words.size()-1; i++)
        {
            unordered_set<char> thisWord = letters(words[i]);
            for(int j = i+1; j < words.size(); j++)
            {
                if(words[i].size() * (words[j].size()) > currMax && exclusive(words[j], thisWord))
                {
                    currMax = words[i].size() * words[j].size();
                }
            }
        }
        return currMax;
    }
};