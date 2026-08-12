class Solution {
public:
    int countAsterisks(string s) {
        bool toCount = true;
        int ans = 0;
        for(char c : s)
        {
            if(c == '|')
            {
                toCount = !toCount;
            }

            if(c == '*' && toCount)
            {
                ans++;
            }
        }
        return ans;
    }
};