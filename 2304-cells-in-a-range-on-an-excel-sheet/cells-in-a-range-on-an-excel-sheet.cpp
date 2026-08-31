class Solution {
public:
    vector<string> cellsInRange(string s) {
        char start = s[0];
        char end = s[3];

        int colStart = s[1] - '0';
        int colEnd = s[4] - '0';

        vector<string> ans;
        for(char i = start; i <= end; i++)
        {
            for(int j = colStart; j <= colEnd; j++)
            {
                string result = "";
                result += i;
                result += j + '0';

                ans.push_back(result);
            }
        }
        return ans;
    }
};