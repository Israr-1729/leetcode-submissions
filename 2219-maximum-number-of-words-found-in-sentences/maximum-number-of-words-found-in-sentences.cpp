class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;

        for(const string &s : sentences)
        {
            int thisWords = 1;
            for(char c : s)
            {
                if(c==' ')
                thisWords++;
            }
            maxWords = max(maxWords, thisWords);
        }
        return maxWords;
    }
};