class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> large(3, INT_MIN);
        vector<int> small(2, INT_MAX);

        //small[0] = smallest. small[1] = 2nd smallest
        for(int a : nums)
        {
            if(a<=small[0])
            {
                small[1] = small[0];
                small[0] = a;
            }

            else if(a<small[1])
            {
                small[1] = a;
            }
        }

        //large[0] = largest. large[1] = 2nd largest. large[2] = 3rd largest.

        for(int a : nums)
        {
            if(a>=large[0])
            {
                large[2] = large[1];
                large[1] = large[0];
                large[0] = a;
            }

            else if(a>=large[1])
            {
                large[2] = large[1];
                large[1] = a;
            }

            else if(a>large[2])
            {
                large[2] = a;
            }

        }
        return max(large[0]*large[1]*large[2], small[0]*small[1]*large[0]);
    }
};