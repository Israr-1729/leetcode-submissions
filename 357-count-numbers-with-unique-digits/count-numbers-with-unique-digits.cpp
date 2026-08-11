class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
        return 1;

        if(n == 1)
        return 10;

        int ans = 10;

        for(int i = 2; i <= n; i++)
        {
            int copy = i;
            int product = 9;
            for(int j = 0; j < i - 1; j++)
            {
                product *= (9 - j);
            }
            ans += product;
        }       
        return ans; 
    }
};