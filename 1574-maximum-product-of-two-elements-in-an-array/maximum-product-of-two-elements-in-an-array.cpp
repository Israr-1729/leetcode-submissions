class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size(); int idx = 0;
        vector<int> copy(size);

        for(int a : nums)
        {
            copy[idx++] = a-1;
        }

        int max1 = INT_MIN; int max2 = INT_MIN; 
        int min1 = INT_MAX; int min2 = INT_MAX;

        for(int a : copy)
        {
            if(a>=max1)
            {
                max2 = max1;
                max1 = a;
            }

            else if(a>=max2)
            {
                max2 = a;
            }
        }

        for(int a : copy)
        {
            
            if(a<=min1)
            {
                min2 = min1;
                min1 = a;
            }

            else if(a<min2)
            {
                min2 = a;
            }
        }
        return max(min1*min2, max1*max2);
    }
};