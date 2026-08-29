class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> alphabets;
        for(char c : s)
        {
            if(isalpha(c))
            alphabets.push_back(c);
        }
        reverse(alphabets.begin(), alphabets.end());

        int idx = 0;
        for(char &c : s)
        {
            if(isalpha(c))
            c = alphabets[idx++];
        }
        return s;
    }
};