class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int currWidth = 0;
        int totalLines = 0;
        for(char c : s)
        {
            if(currWidth + widths[c-'a'] > 100)
            {
                currWidth = 0;
                totalLines++;
            }
            currWidth += widths[c-'a'];
        }
        return {(currWidth > 0 ? totalLines + 1 : totalLines), currWidth};
    }
};