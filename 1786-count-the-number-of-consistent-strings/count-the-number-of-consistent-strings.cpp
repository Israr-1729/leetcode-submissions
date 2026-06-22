class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedLetters;
        for(char c : allowed)
        {
            allowedLetters.insert(c);
        }

        int count = 0;
        for(string a : words)
        {
            for(char c : a)
            {
                if(allowedLetters.find(c)==allowedLetters.end())
                {
                count--;
                break;
                }
            }
            count++;
        }
        return count>=0 ? count : 0;
    }
};