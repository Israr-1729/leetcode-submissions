class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN; int max2 = INT_MIN; 
        for(int a : nums)
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
        return (max1-1)*(max2-1);
    }
};