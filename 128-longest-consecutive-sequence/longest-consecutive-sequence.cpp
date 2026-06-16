class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int maxStreak = 0;

        for(int num : st)
        {
            if(st.find(num - 1) != st.end())
                continue;

            int curr = num;
            int streak = 1;

            while(st.find(curr + 1) != st.end())
            {
                curr++;
                streak++;
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak;
    }
};