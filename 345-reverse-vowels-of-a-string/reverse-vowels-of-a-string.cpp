class Solution {
public:

    bool isvowel(char c)
    {
        char copy = tolower(c);
        if(copy == 'a' || copy == 'e' || copy == 'i' || copy == 'o' || copy == 'u')
        return true;

        return false;
    }
    string reverseVowels(string s) {
        vector<char> vowels;
        for(char c : s)
        {
            if(isvowel(c))
            vowels.push_back(c);
        }

        reverse(vowels.begin(), vowels.end());
        int i = 0;

        string result = "";

        for(char c : s)
        {
            if(!isvowel(c))
            {
                result.push_back(c);
            }

            else
            result.push_back(vowels[i++]);
        }
        return result;
    }
};