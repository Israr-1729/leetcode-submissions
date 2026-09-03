class Solution {
public:

    unordered_map<string, int> mp;
    void frequencerOdd(vector<vector<int>> &oddFreq, const string &s)
    {
        vector<int> result(26, 0);
        for(int i = 1; i < s.size(); i+=2)
        result[s[i] - 'a']++;

        oddFreq.push_back(result);
    }

    void frequencerEven(vector<vector<int>> &evenFreq, const string &s)
    {
        vector<int> result(26, 0);
        for(int i = 0; i < s.size(); i+=2)
        result[s[i] - 'a']++;

        evenFreq.push_back(result);
    }

    string vectorToString(const vector<int> &odd, const vector<int> &even)
    {
        string result = "";
        for(int i : odd)
        {
            result += to_string(i);
            result += '#';
        }

        result += '$';

        for(int i : even)
        {
            result += to_string(i);
            result += '#';
        }
        return result;
    }


    int numSpecialEquivGroups(vector<string>& words) {
        vector<vector<int>> oddFreq;
        vector<vector<int>> evenFreq;
        for(string &s : words)
        {
            frequencerOdd(oddFreq, s);
            frequencerEven(evenFreq, s);
        }

        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            mp[vectorToString(oddFreq[i], evenFreq[i])]++;
        }
    return mp.size();
    }
};