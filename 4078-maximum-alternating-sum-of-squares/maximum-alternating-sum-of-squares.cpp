class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int start = 0; int end = nums.size()-1;
        vector<int> reArranged(nums.size(), 0);
        

sort(nums.begin(), nums.end(), [](int a, int b) {
    return abs(a) < abs(b);
});
        reverse(nums.begin(), nums.end()); 
        int idx = 0;
        for(int i = 0; i < nums.size(); i+=2)
        {
            reArranged[i] = nums[idx++];
        }

        for(int i = 1; i < nums.size(); i+=2)
        {
            reArranged[i] = nums[idx++];
        }

        long long score = 0;
        bool add = true;


        for(int i : reArranged)
        {
            if(add)
            {
                score += 1LL * i * i;
                add = !add;
            }

            else
            {
                score -= 1LL * i * i;
                add = !add;
            }
        }
        return score;
    }
};