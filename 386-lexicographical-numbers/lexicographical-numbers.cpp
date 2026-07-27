class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> result(n);
        for(int i = 1; i<=n; i++)
        {
            result[i-1] = to_string(i);
        }

        sort(result.begin(), result.end());

        vector<int> act;
        for(string &s : result)
        {
            act.push_back(stoi(s));
        }
    return act;
    }
};