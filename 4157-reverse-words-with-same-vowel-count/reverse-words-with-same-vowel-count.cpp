class Solution {
public:

    int vowelCounter (const string &s)
    {
        int vowelCount = 0;
        for(char c : s)
        {
            if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u')
            vowelCount++;
        }
        return vowelCount;
    }

    string reverseWords(string s) {
        int i = 0; int size = s.size();

        int vowelCountChecker = -1;
        string result = "";
        while(i < size)
        {
            string newWord = "";
            while(i < size && s[i] != ' ')
            {
                newWord += s[i];
                i++;
            }

            int currentVowels = vowelCounter(newWord);

            if(vowelCountChecker == -1)
            {
                vowelCountChecker = currentVowels;
                result += newWord;
                result += ' ';
                i++;
                continue;
            }

            if(currentVowels == vowelCountChecker)
            {
                reverse(newWord.begin(), newWord.end());
                result += newWord;
                result += ' ';
            }

            else
            {
                result += newWord;
                result += ' ';
            }

            i++;
        }

        result.pop_back();
        return result;
    }
};