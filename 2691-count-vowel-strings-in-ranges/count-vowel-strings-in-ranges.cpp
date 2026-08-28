class Solution {
public:

    bool isAlpha(char c)
    {
        if(c == 'a' || c=='e' || c=='i' || c == 'o' || c =='u')
        return true;
        return false;
    }

    bool isTrue(const string &s)
    {
        if(isAlpha(s.front()) && isAlpha(s.back()))
        return true;
        return false;
    }

        vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int runningCount = 0;
        vector<int> runningVector;

        for(const string &s : words)
        {
            runningVector.push_back(runningCount);

            if(isTrue(s))
            runningCount++;
        }

        vector<int> result;
        for(auto &a : queries)
        {
            if(isTrue(words[a[1]]))
            result.push_back(runningVector[a[1]] - runningVector[a[0]] + 1);

            else
            result.push_back(runningVector[a[1]] - runningVector[a[0]]);
        }
        return result;
    }
};