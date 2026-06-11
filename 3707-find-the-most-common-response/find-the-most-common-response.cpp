class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int size = responses.size();
        vector<vector<string>> noDuplicates(size);
        for(int i = 0; i<size; i++)
        {
            unordered_map <string, bool> isFound;
            vector<string> thisVector;
            int thisSize = responses[i].size();

            for(int j = 0; j<thisSize; j++)
            {
                if(isFound.find(responses[i][j])==isFound.end())
                {
                    thisVector.push_back(responses[i][j]);
                    isFound[responses[i][j]] = true;
                }
            }
            noDuplicates[i] = thisVector;
        }

        unordered_map <string, int> count;
        for(int i = 0; i<size; i++)
        {
            int thisSize = noDuplicates[i].size();
            for(int j = 0; j<thisSize; j++)
            {
                count[noDuplicates[i][j]]++;
            }
        }

        vector<string> result;
        int maxCount = INT_MIN;

        for(auto &p : count)
        {
            if(p.second>maxCount)
            {
                maxCount = p.second;
            }
        }

        for(auto &p : count)
        {
            if(p.second == maxCount)
            result.push_back(p.first);
        }

        sort(result.begin(), result.end());
        return result[0];
        
    }
};