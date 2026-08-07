class Solution {
public:

    bool isDigit(char c)
    {
        if(c>='0' && c<='9')
        return true;

        return false;
    }

    string removeLeadingZeroes(string s)
{
    int i = 0;

    while(i < s.size() && s[i] == '0')
        i++;

    return s.substr(i);
}
    int numDifferentIntegers(string word) {
        unordered_set<string> integers;
        int i = 0;
        int size = word.size();

        while(i<size)
        {
            if(isDigit(word[i]))
            {
                string newNum = "";
                while(i < size && isDigit(word[i]))
                {
                    newNum += word[i];
                    i++;
                }

                string toAdd = removeLeadingZeroes(newNum);
                integers.insert(toAdd);
            }
            i++;
        }
        return integers.size();
    }
};