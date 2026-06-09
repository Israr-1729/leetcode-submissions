class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> result;

        while (true) {
            vector<int> row;
            bool added = false;

            for (auto& p : freq) {
                if (p.second > 0) {
                    row.push_back(p.first);
                    p.second--;
                    added = true;
                }
            }

            if (!added) break;

            result.push_back(row);
        }

        return result;
    }
};