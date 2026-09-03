class Solution {
public:
    string greatestLetter(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for(char c : s)
        {
            if(islower(c))
            lower[c-'a']++;

            if(isupper(c))
            upper[c-'A']++;
        }
        string result = "";
        for(int i = 0; i < 26; i++)
        {
            if(lower[i] != 0 && upper[i] != 0)
            {
                result = "";
                result += i+'A';
            }
        }
        return result;
    }
};