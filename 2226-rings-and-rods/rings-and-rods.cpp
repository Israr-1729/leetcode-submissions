class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, unordered_set<char>> mp;

        for(int i = 0; i < rings.size(); i++)
        {
            if(isdigit(rings[i]))
            {
                mp[rings[i] - '0'].insert(rings[i-1]);
            }
        }

        int ans = 0;
        for(auto &a : mp)
        {
            if(a.second.contains('R') && a.second.contains('G') && a.second.contains('B'))
            ans++;
        }
        return ans;
    }
};