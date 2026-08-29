class Solution {
public:
    bool checkRecord(string s) {
        int aCount = 0;
        int consecutiveL = 0;
        for(char c : s)
        {
            if(c == 'A')
            {
                aCount++;
            }

            if(c == 'L')
            {
                consecutiveL++;
            }

            else
            {
                consecutiveL = 0;
            }
            if(aCount >= 2 || consecutiveL >= 3)
            return false;
        }
        return true;
    }
};