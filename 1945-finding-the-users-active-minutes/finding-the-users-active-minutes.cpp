class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> userMinutes;
        for(auto &a : logs)
        {
            userMinutes[a[0]].insert(a[1]);
        }

        vector<int> result(k, 0);
        for(auto &a : userMinutes)
        {
            result[a.second.size()-1]++;
        }
        return result;

    }
};