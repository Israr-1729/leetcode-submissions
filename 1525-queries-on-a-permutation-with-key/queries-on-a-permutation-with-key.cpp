class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> result;
        unordered_map<int, int> permutation;
        for(int i = 1; i <= m; i++)
        {
            permutation[i] = i - 1;
        }

        for(int i : queries)
        {
            result.push_back(permutation[i]);
            

            for(auto &v : permutation)
            {
                if(v.second < permutation[i])
                v.second++;
            }

            permutation[i] = 0;

        }
        return result;
        
    }
};