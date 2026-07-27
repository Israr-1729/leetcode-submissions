class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN; long long max2 = LLONG_MIN; long long max3 = LLONG_MIN;

        for(int a : nums)
        {
            if(a>max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = a;
            }

            else if(a>max2 && a!=max1)
            {
                max3 = max2;
                max2 = a;
            }

            else if(a>max3 && a!=max2 && a!=max1)
            {
                max3 = a;
            }
        }
        return max3 == LLONG_MIN ? max1 : max3;
    }
};