class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid.size();
        unordered_map<int, int> history;
        for(auto &a : grid)
        {
            for(int i : a)
            history[i]++;
        }

        int missing = size*size;
        int doubled = size*size;
        for(int i = 1; i<=size*size; i++)
        {
            if(history[i]==0)
            missing = i;

            if(history[i]==2)
            doubled = i;
        }
        return {doubled, missing};
    }
};