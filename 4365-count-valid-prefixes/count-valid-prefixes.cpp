class Solution {
public:
    int countValidPrefixes(string s) {
        int runningZero = 0;
        int runningOne = 0;
        int count = 0;

        for(char c : s)
        {
            if(c=='0')
            runningZero++;

            else
            runningOne++;

            if(abs(runningOne - runningZero) <= 1)
            count++;
        }
        return count;
    }
};