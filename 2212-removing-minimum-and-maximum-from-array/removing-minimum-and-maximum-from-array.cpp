class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIDX = -1; int maxIDX = -1;
        int minm = INT_MAX; int maxm = INT_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= maxm)
            {
                maxm = nums[i];
                maxIDX = i;
            }

            if(nums[i] <= minm)
            {
                minm = nums[i];
                minIDX = i;
            }
        }
        

        int cuttingFromLeft = max(maxIDX, minIDX) + 1;
        int cuttingFromRight = nums.size() - min(maxIDX, minIDX);
        int cuttingFromBoth = (min(maxIDX, minIDX) + 1) + (nums.size() - max(maxIDX, minIDX));


        /*cout<<cuttingFromLeft<<" "<<cuttingFromRight<<" "<<cuttingFromBoth<<"\n";
        cout<<minm<<" "<<maxm<<"\n";
        cout<<minIDX<<" "<<maxIDX<<"\n";
        cout<<(min(maxIDX, minIDX) + 1)<<" "<<(nums.size() - max(maxIDX, minIDX))<<"\n";*/
        return min(min(cuttingFromLeft, cuttingFromRight), cuttingFromBoth);
    }
};