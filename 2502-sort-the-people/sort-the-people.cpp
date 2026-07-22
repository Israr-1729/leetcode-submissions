class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mp; int idx = 0;
        for(int a : heights)
        {
            mp[a] = names[idx++];
        }

        sort(heights.begin(), heights.end());
        reverse(heights.begin(), heights.end());
        vector<string> result;

        for(int a : heights)
        {
            result.push_back(mp[a]);
        }
        return result;
    }
};