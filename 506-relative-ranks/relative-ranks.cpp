class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> ranks;
        int rank = 1;
        for(int i = score.size()-1; i >= 0; i--)
        {
            ranks[sorted[i]] = rank++;
        }

        vector<string> result;

        for(int i : score)
        {
            if(ranks[i] == 1)
            result.push_back("Gold Medal");

            else if(ranks[i] == 2)
            result.push_back("Silver Medal");

            else if(ranks[i] == 3)
            result.push_back("Bronze Medal");

            else
            result.push_back(to_string(ranks[i]));
        }
        return result;
    }
};