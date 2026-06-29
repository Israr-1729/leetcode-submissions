class Solution {
public:
    int minimum(int a, int b) {
        return a < b ? a : b;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < nums.size(); i++)
            indices[nums[i]].push_back(i);

        int n = nums.size();

        vector<int> result;

        for (int q : queries) {

            const vector<int>& pos = indices[nums[q]];

            if (pos.size() == 1) {
                result.push_back(-1);
                continue;
            }

            int idx = lower_bound(pos.begin(), pos.end(), q) - pos.begin();

            int prev =
                pos[(idx - 1 + pos.size()) % pos.size()];

            int next =
                pos[(idx + 1) % pos.size()];

            int d1 = abs(q - prev);
            d1 = minimum(d1, n - d1);

            int d2 = abs(q - next);
            d2 = minimum(d2, n - d2);

            result.push_back(minimum(d1, d2));
        }

        return result;
    }
};