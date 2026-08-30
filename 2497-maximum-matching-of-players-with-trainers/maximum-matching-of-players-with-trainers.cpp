class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        vector<int> &g = players;
        vector<int> &s = trainers;
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int sIDX = 0;
        int count = 0;

        for(int i = 0; i < g.size() && sIDX < s.size(); i++)
        {
            if(s[sIDX] >= g[i])
            {
            count++;
            sIDX++;
            }
        } 

        return count;  
        
    }
};