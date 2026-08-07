class Solution {
public:

    bool canBeMade(vector<int> charsCopy, const string & word)
    {
        for(char c : word)
        {
            if(charsCopy[c-'a'] == 0)
            return false;

            else
            charsCopy[c-'a']--;
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {

        vector<int> charsCopy(26, 0);
        for(char c : chars)
        {
            charsCopy[c-'a'] ++;
        }

        int ans = 0;
        for(const string &s : words)
        {
            if(canBeMade(charsCopy, s))
            ans+=s.size();
        }
        return ans;
    }
};