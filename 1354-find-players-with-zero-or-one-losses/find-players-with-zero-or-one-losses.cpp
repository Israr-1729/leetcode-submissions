class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        unordered_set<int> players;
        int matchesSize = matches.size();
        for(int i = 0; i<matchesSize; i++)
        {
            losses[matches[i][1]]++;
            players.insert(matches[i][0]);
            players.insert(matches[i][1]);
        }

        vector<vector<int>> result(2);
        for(auto x : players)
        {
            if(losses[x]==0)
            result[0].push_back(x);

            if(losses[x]==1)
            result[1].push_back(x);
        }
        for(int i = 0; i<2; i++)
        {
            sort(result[i].begin(), result[i].end());
        }
    return result;
    }
};