class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {

        unordered_map<int, long long> cnt;
        multiset<long long> ms;
        vector<long long> ans;

        for (int i = 0; i < nums.size(); i++) {

            if (cnt.count(nums[i]) && cnt[nums[i]] > 0)
                ms.erase(ms.find(cnt[nums[i]]));

            cnt[nums[i]] += freq[i];

            if (cnt[nums[i]] > 0)
                ms.insert(cnt[nums[i]]);

            ans.push_back(ms.empty() ? 0 : *ms.rbegin());
        }

        return ans;
    }
};