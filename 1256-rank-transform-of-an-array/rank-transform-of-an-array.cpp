class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        int size = arr.size();
        unordered_map<int, int> ranks;
        int idx = 1;

        for(int i = 0; i<size; i++)
        {
            if(ranks.contains(copy[i]))
            continue;

            else
            {
                ranks[copy[i]] = idx++;
            }
        }
        
        vector<int> result(size);
        for(int i = 0; i<size; i++)
        {
            result[i] = ranks[arr[i]];
        }
        return result;
    }
};