class Solution {
public:

    int otherFactor(int num)
    {
        int root = (int) sqrt(num);

        if(root * root == num)
        return -1;

        int ans = -1;
        for(int i = 2; i * i < num; i++)
        {
            if(num % i == 0)
            {
                if(ans != -1)
                return -1;

                else
                ans = i;
            }
        }

        return ans;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)
        {
            int factor = otherFactor(i);
            if(factor != -1)
            {
                sum += 1 + i + factor + i/factor;
            }
        }
        return sum;
    }
};