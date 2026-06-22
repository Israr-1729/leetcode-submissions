class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;
        for(char c : s)
        {
            freq[c]++;
        }

        unordered_map<int, int> frequencyOfFrequency;
        for(auto &a : freq)
        {
            frequencyOfFrequency[a.second]++;
        }

        vector<int> fof;
        for(auto &a : frequencyOfFrequency)
        {
            fof.push_back(a.second);
        }

        int maxm = INT_MIN;
        for(int a : fof)
        {
            maxm = max(maxm, a);
        }
        
        int maxFreq = INT_MIN;
        for(auto &a : frequencyOfFrequency)
        {
            if(a.second==maxm)
            maxFreq = max(a.first, maxFreq);

        }

        unordered_set<char> result;

        for(char c : s)
        {
            if(freq[c]==maxFreq)
            result.insert(c);
        }

        string stringResult = "";
        for(auto &a : result)
        {
            stringResult += a;
        }
        return stringResult;
    }
};