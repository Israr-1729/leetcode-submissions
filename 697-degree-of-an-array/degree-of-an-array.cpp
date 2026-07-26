class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> frequency;
        unordered_map<int, int> firstOccurrence;
        unordered_map<int, int> lastOccurrence;

        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            if(!firstOccurrence.contains(nums[i]))
                firstOccurrence[nums[i]] = i;

            lastOccurrence[nums[i]] = i;
            frequency[nums[i]]++;
        }

        int degree = 0;
        for(auto &a : frequency)
            degree = max(degree, a.second);

        int result = size;

        for(auto &a : frequency)
        {
            if(a.second == degree)
            {
                result = min(result,
                             lastOccurrence[a.first] - firstOccurrence[a.first] + 1);
            }
        }

        return result;
    }
};