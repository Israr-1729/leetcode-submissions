class Solution {
public:
    long long summation(const string &s)
    {
        string result = "";
        for(char c : s)
        {
            result += to_string(c-'a');
        }
        return stoll(result);
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return (summation(firstWord) + summation(secondWord) == summation(targetWord));
    }
};