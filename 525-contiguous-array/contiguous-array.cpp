class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> prefixSum;
        int runningSum = 0;
        for(int a : nums)
        {
            runningSum += ((a==0) ? -1 : 1);
            prefixSum.push_back(runningSum);
        }

        unordered_map<int, vector<int>> doesContain;
        int maxVal = INT_MIN;

        doesContain[0].push_back(-1);
        for(int i = 0; i<prefixSum.size(); i++)
        {
            doesContain[prefixSum[i]].push_back(i);
        }

        for(auto &a : doesContain)
        {
            vector<int> v = a.second;
            int size = v.size();

            maxVal = max(maxVal, v[size-1]-v[0]);
        }
        return maxVal;
    }
};