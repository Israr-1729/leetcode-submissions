class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map <int, char>letterWeights;
        char c = 'a';
        for(int i = 25; i>=0; i--)
        {
            letterWeights[i] = c++;
        }
        
        int wordsSize = words.size();
        string result = "";
        for(int i = 0; i<wordsSize; i++)
        {
            int thisWordSize = words[i].size();
            int sum = 0;
            for(int j = 0; j<thisWordSize; j++)
            {
                sum += weights[words[i][j]-'a'];
            }
            result += letterWeights[sum%26];
        }
        return result;
    }
};