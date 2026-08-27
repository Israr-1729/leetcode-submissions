class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int maxm1 = INT_MIN; int maxm2 = INT_MIN; int minm = INT_MAX;
        for(int i : nums)
        {
            if(i >= maxm1)
            {
                maxm2 = maxm1;
                maxm1 = i;
            }

            else if(i > maxm2)
            {
                maxm2 = i;
            }

            if(i < minm)
            {
                minm = i;
            }
        }
        return maxm1 + maxm2 - minm;
    }
};