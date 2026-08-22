class Solution {
public:
    bool numDivisors(int n)
    {
        if((int) sqrt(n) * (int) sqrt(n) == n)
        return false;

        int divCount = 0;
        for(int i = 1; i * i < n; i++)
        {
            if(n % i == 0)
            {
            divCount++;
            }

            if(divCount > 2)
            return false;
        }
        if(divCount == 2)
        return true;

        return false;
    }

    int divisor(int n)
    {
        for(int i = 2; i * i < n; i++)
        {
            if(n % i == 0)
            return i;
        }
        return -1;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i : nums)
        {
            if(numDivisors(i))
            {
                int otherDivider = divisor(i);
                ans += 1 + i + otherDivider + i/otherDivider;
            }
        }
        return ans;
    }
};