class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i = 0; int size = s.size();
        vector<vector<int>> result;

        while(i < size)
        {
            char newCheck = s[i];
            int start = i;
            int end = i;

            while(end < size && s[end] == newCheck)
            {
                end++;
            }

            if(end-start >= 3)
            result.push_back({start, end-1});
            i = end;
        }
        return result;
    }
};