class Solution {
public:


    string thisPattern(string thisString)
    {
        unordered_map<char, int> patternMap;
        int size = thisString.size();
        int idx = 0;
        string thisPattern = "";

        for(int i = 0; i<size; i++)
        {
            if(patternMap.find(thisString[i])!=patternMap.end())
            {
                thisPattern.push_back(patternMap[thisString[i]]+'a');
            }
            else
            {
                patternMap[thisString[i]] = idx++;
                thisPattern.push_back(patternMap[thisString[i]]+'a');
            }
        }
        return thisPattern;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    
        string patternCode = thisPattern(pattern);
        int wordsSize = words.size();
        int patternSize = pattern.size();
        vector<string> result;
        for(int i = 0; i<wordsSize; i++)
        {
            if(words[i].size() != patternSize)
            continue;
            if(thisPattern(words[i])==patternCode)
            result.push_back(words[i]);
        }
        return result;
    }
};