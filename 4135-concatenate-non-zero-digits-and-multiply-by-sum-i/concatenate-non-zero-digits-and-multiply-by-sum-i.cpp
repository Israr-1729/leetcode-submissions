class Solution {
public:
    long long sumAndMultiply(int copy) {
        int newN = 0;
        int sum = 0;
        while(copy>0)
        {
            int digit = copy%10;
            if(digit!=0)
            {
                newN = newN*10 + digit;
                sum += digit;
            }
            copy /= 10;
        }

        long long x = 0;
        while(newN)
        {
            x = x*10 + newN%10;
            newN/=10;
        }
        return 1LL*x*sum;
    }
};