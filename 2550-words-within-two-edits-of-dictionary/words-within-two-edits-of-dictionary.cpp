class Solution {
public:

    bool difference(string &word1, string&word2)
    {
        if(word1.size() != word2.size())
        return false;

        int unequal = 0;
        for(int i = 0, size = word1.size(); i<size; i++)
        {
            if(word1[i] != word2[i])
            unequal++;
        }
        if(unequal>2)
        return false;
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(string word1 : queries)
        {
            for(string word2 : dictionary)
            {
                if(difference(word1,word2))
                {
                    result.push_back(word1);
                    break;
                }
            }
        }
        return result;
    }
};