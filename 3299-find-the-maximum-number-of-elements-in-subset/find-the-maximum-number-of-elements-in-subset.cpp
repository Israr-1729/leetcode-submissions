class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (auto& n : nums) freq[n]++;

        int res = (freq[1] - 1) | 1;
        freq.erase(1);

        for (auto& f : freq) {
            long long x = f.first;
            long long sq = sqrt(x);

            if (sq * sq == x && freq.count(sq) && freq[sq] > 1) continue;

            int n = 0;

            while (freq.count(x) && freq[x] > 1) {
                n += 2;
                x *= x;
            }

            res = fmax(res, n + ((freq.count(x) << 1) - 1));
        }

        return res;
    }
};