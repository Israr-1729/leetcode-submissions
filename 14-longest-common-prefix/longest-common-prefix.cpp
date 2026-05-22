class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        int common = strs[0].size();
        int maxCommon = 0;
        for(int i = 1; i < size; i++)
        {
            maxCommon = 0;
            for(int j = 0; j<strs[i].size() && j<strs[0].size(); j++)
            {
                if(strs[0][j] == strs[i][j])
                maxCommon++;

                else
                break;
            }

            if(maxCommon < common)
            common = maxCommon;
        }

        string prefix;
        for(int i = 0; i<common; i++)
        prefix.push_back(strs[0][i]);

        return prefix;
        
    }
};