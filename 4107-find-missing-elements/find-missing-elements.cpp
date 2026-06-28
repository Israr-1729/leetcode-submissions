class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minm = INT_MAX;
        int maxm = INT_MIN;
        unordered_set<int> numbers;

        for(int a : nums)
        {
            minm = min(minm, a);
            maxm = max(maxm, a);
            numbers.insert(a);
        }

        vector<int> result;
        for(int i = minm; i<=maxm; i++)
        {
            if(numbers.contains(i))
            continue;
            else
            result.push_back(i);
        }
    return result;
    }
};