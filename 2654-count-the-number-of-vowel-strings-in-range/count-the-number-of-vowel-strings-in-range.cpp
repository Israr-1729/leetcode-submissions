class Solution {
public:

    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
        return false;
    }
    bool isVowelString(const string &s)
    {
        return isVowel(s.front()) && isVowel(s.back());
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++)
        {
            if(isVowelString(words[i]))
            count++;
        }
        return count;
    }
};