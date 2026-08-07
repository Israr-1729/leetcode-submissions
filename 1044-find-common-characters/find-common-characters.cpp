class Solution {
public:
    vector<vector<int>> freq(vector < string > & words) {
        vector<vector<int>> result;
        for (const string& s : words) {
            vector<int> thisResult(26, 0);
            for (char c : s) {
                thisResult[c - 'a']++;
            }
            result.push_back(thisResult);
        }
        return result;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> freqVector = freq(words);
        vector<int> result(26, INT_MAX);
        for(auto &a : freqVector)
        {
            for(int i = 0; i<26; i++)
            {
                result[i] = min(result[i], a[i]);
            }
        }

        vector<string> ans;

        for(int j = 0; j<26; j++)
        {
            for(int i = 0; i<result[j]; i++)
            {
                string thisAns = "";
                thisAns += (j + 'a');
                ans.push_back(thisAns);
            }
        }
        return ans;
    }
};