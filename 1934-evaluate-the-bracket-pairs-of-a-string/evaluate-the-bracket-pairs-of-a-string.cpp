class Solution {
public:
    vector<vector<int>> brackets(const string &s)
    {
        vector<vector<int>> result;
        vector<int> toAdd(2, -1);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                toAdd[0] = i;
            }

            if(s[i] == ')')
            {
                toAdd[1] = i;
            }

            if(toAdd[1] != -1)
            {
                result.push_back(toAdd);
                toAdd[0] = -1;
                toAdd[1] = -1;
            }
        }
        return result;
    }

    string resultMaker(const vector<string> &replaced, const string &s, const vector<vector<int>> &bracketPairs)
    {
        string result = "";
        int idx = 0;   
        int i = 0;

        while(i < s.size())
        {
            if(idx < bracketPairs.size() && i == bracketPairs[idx][0])
            {
                result += replaced[idx];
                i = bracketPairs[idx][1];
                idx++;
            }

            else
            {
                result += s[i];
            }
            i++;
        }
        return result;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> key;
        for(auto &a : knowledge)
        {
            key[a[0]] = a[1];
        }

        vector<vector<int>> bracketPairs = brackets(s);
        vector<string> replaced;
        for(auto &a : bracketPairs)
        {
            string toCheck = s.substr(a[0] + 1, a[1] - a[0] -1);
            if(key.contains(toCheck))
            replaced.push_back(key[toCheck]);

            else
            replaced.push_back("?");
        }
        return resultMaker(replaced, s, bracketPairs);
    }
};