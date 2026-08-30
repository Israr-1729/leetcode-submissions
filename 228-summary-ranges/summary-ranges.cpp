class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int idx = 0;
        int size = nums.size();
        vector<string> result;
        while(idx < size)
        {
            string newRange = "";
            newRange += to_string(nums[idx]);

            long long start = nums[idx];
            long long i = nums[idx];

            while(idx < size && i == nums[idx])
            {
                i++;
                idx++;
            }
            
            if(i == 1LL * start+1)
            {
                result.push_back(newRange);
            }

            else
            {
                newRange += "->";
                newRange += to_string(i-1);
                result.push_back(newRange);
            }
        }
        return result;
    }
};