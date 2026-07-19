class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;

        int ans = 0;
        unordered_set<char> vis;

        for (auto &[c, freq] : mp) {
            if (vis.count(c)) continue;

            char mirror;
            if (islower(c))
                mirror = 'z' - (c - 'a');
            else
                mirror = '9' - (c - '0');

            int mfreq = mp.count(mirror) ? mp[mirror] : 0;
            ans += abs(freq - mfreq);

            vis.insert(c);
            vis.insert(mirror);
        }

        return ans;
    }
};