class Solution {
public:
    vector<string> parser(const string &s)
    {
        vector<int> commas(3, -1);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ',')
            {
                if(commas[0] == -1)
                commas[0] = i;

                else if(commas[1] == -1)
                commas[1] = i;

                else
                commas[2] = i;
            }
        }

        vector<string> result;
        result.push_back(s.substr(0, commas[0]));
        result.push_back(s.substr(commas[0]+1, commas[1] - commas[0] - 1));
        result.push_back(s.substr(commas[1]+1, commas[2] - commas[1] - 1));
        result.push_back(s.substr(commas[2]+1));

        return result;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> result;
        unordered_map<string, vector<pair<int, string>>> name_time_city;

        for(const string &s : transactions)
        {
            const vector<string> features = parser(s);

            name_time_city[features[0]].push_back(
                {stoi(features[1]), features[3]}
            );
        }

        for(const string &s : transactions)
        {
            const vector<string> features = parser(s);

            if(stoi(features[2]) > 1000)
            {
                result.push_back(s);
                continue;
            }

            for(auto &a : name_time_city[features[0]])
            {
                if(abs(a.first - stoi(features[1])) <= 60 &&
                   a.second != features[3])
                {
                    result.push_back(s);
                    break;
                }
            }
        }

        return result;
    }
};