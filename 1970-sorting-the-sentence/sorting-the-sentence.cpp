class Solution {
public:
    string sortSentence(string s) {
        int numWords = 1;
        for(char c : s)
        {
            if(c==' ')
            numWords++;
        }

        vector<string> sortedWords(numWords, "");
        string newWord = "";
        for(char c : s)
        {
            if(isalpha(c))
            newWord += c;

            else if(isdigit(c))
            {
                sortedWords[c-'0' - 1] = newWord;
                newWord = "";
            }
        }

        string result = "";
        for(auto &s : sortedWords)
        {
            result += s;
            result += ' ';
        }

        result.pop_back();
        return result;
        
    }
};