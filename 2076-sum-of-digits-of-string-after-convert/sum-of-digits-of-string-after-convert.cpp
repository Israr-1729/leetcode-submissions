class Solution {
public:
    string charToDigit(const string &s)
    {
        string result = "";
        for(char c : s)
        {
            result += to_string(c-'a' + 1);
        }
        return result;
    }

    void sum(string &s)
    {
        string copy = s;
        int summation = 0;
        for(char c : copy)
        {
            summation += c-'0';
        }
        s = to_string(summation);
    }
    int getLucky(string s, int k) {
        string transformed = charToDigit(s);
        for(int i = 0; i < k; i++)
        {
            sum(transformed);
        }
        return stoi(transformed);
    }
};