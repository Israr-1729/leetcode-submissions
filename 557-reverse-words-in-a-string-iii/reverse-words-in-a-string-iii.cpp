class Solution {
public:
    string reverseWords(string s) {

        s += ' ';
        string newWord = "";
        string result = "";
        for(char c : s)
        {
            if(c == ' ')
            {
                reverse(newWord.begin(), newWord.end());
                result += newWord;
                result += " "; 
                newWord = "";
                continue;
            }

            else
            {
                newWord += c;
            }
        }

    result.pop_back();
    return result;
        
    }
};