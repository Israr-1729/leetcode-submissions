class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int copy = x;
        int sum = 0;
        while(copy>0)
        {
            sum += copy%10;
            copy/=10;
        }

        if(x%sum==0)
        return sum;
        return -1;
        
    }
};