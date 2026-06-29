class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        // 1. group indices by value
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<long long> res(n, 0);

        // 2. process each group
        for (auto &it : pos) {
            vector<int> &v = it.second;
            int m = v.size();

            if (m == 1) {
                res[v[0]] = 0;
                continue;
            }

            // prefix sum of indices
            vector<long long> prefix(m, 0);
            prefix[0] = v[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + v[i];
            }

            // 3. compute answer for each occurrence
            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;

                // left side contribution
                if (i > 0) {
                    left = 1LL * i * v[i] - prefix[i - 1];
                }

                // right side contribution
                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) -
                            1LL * (m - i - 1) * v[i];
                }

                res[v[i]] = left + right;
            }
        }

        return res;
    }
};