class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> a;

        for (auto &v : reservedSeats) {
            a[v[0]].insert(v[1]);
        }

        // Every completely empty row can fit 2 families.
        long long ans = 2LL * (n - a.size());

        for (auto &[row, seats] : a) {
            bool left =
                !seats.contains(2) &&
                !seats.contains(3) &&
                !seats.contains(4) &&
                !seats.contains(5);

            bool right =
                !seats.contains(6) &&
                !seats.contains(7) &&
                !seats.contains(8) &&
                !seats.contains(9);

            bool middle =
                !seats.contains(4) &&
                !seats.contains(5) &&
                !seats.contains(6) &&
                !seats.contains(7);

            if (left && right)
                ans += 2;
            else if (left || right || middle)
                ans += 1;
        }

        return ans;
    }
};