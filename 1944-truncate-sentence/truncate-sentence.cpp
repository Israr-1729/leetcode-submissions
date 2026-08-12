class Solution {
public:
    string truncateSentence(string s, int k) {
        string result = "";
        int spaceCount = 0;
        for(char c : s)
        {
            if(c == ' ')
            spaceCount++;

            if(spaceCount == k)
            break;

            result += c;
        }
        return result;
    }
};