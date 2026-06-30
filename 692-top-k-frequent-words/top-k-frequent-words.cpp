class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(string &s : words)
        {
            freq[s]++;
        }

        int highestFrequency = INT_MIN;
        for(auto &p : freq)
        {
            highestFrequency = max(highestFrequency, p.second);
        }

        vector<string> result;
        for(int fr = highestFrequency; fr>0; fr--)
        {
            vector<string> thisResult;
            for(auto &p : freq)
            {
                if(p.second == fr)
                thisResult.push_back(p.first);
            }
            sort(thisResult.begin(), thisResult.end());
            for(string &s : thisResult)
            result.push_back(s);

            if(result.size()>k)
            break;
        }
        while(result.size()>k)
        result.pop_back();

        return result;
    }
};