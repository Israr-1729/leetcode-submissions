class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;

        for (int num : nums) {
            int complement = k - num;

            if (freq[complement] > 0) {
                ans++;
                freq[complement]--;
            } else {
                freq[num]++;
            }
        }

        return ans;
    }
};