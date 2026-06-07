class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int totalWords = words.size();
        vector<int> result;
        for(int i = 0; i<totalWords; i++)
        {
            int thisSize = words[i].size();
            for(int j = 0; j<thisSize; j++)
            {
                if(words[i][j]==x)
                {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};