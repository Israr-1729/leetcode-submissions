class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy = strs;
        int size = strs.size();
        for(int i = 0; i<size; i++)
        { 
            sort(copy[i].begin(), copy[i].end());
        }
        vector<vector<string>> result;

        for(int i = 0; i<size; i++)
        {
            if (copy[i] == "/ignore") continue;
            vector<string> group = {strs[i]};
            for(int j = i+1; j<size; j++)
            {
                if(copy[i]==copy[j])
                {
                    group.push_back(strs[j]);
                    copy[j] = "/ignore";
                }

            }
            copy[i] = "/ignore";
            result.push_back(group);
        }
        return result;
    }
};

