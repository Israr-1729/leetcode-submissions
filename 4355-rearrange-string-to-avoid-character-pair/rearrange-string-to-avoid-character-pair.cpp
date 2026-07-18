class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int> letters(26, 0);

        int occY = 0;
        for(char c : s)
        {
            if(c==y)
            occY++;
        }

        string result = "";
        for(int i = 0; i<occY; i++)
        {
            result += y;
        }

        for(char c : s)
        {
            if(c != y)
            result += c;
        }
        return result;
    }
};