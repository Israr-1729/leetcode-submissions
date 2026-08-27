class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int onesCount = 0;
        for(char c : s)
        {
            if(c == '1')
            onesCount++;
        }

        int zeroesCount = s.size()-onesCount;
        
        string result = "";
        for(int i = 0; i < onesCount-1; i++)
        {
            result.push_back('1');
        }

        for(int i = 0; i < zeroesCount; i++)
        {
            result.push_back('0');
        }

        result.push_back('1');
        return result;
        
    }
};