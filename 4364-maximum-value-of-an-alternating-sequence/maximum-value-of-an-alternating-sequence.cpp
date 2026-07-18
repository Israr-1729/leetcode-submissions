class Solution {
public:
    long long maximumValue(int n, int s, int m) {

        //7, 14, 13

        if(n==1)
        return s;
        //n is even. total elements after s is odd = n-1. Addition happens n/2 times. -1 Happens n-1/2 times.
        long long result = s;
        if(n%2==0)
        {
            result += 1LL*m*(n/2);
            result-=(n-1)/2;
        }

        // n is odd. total elements after s is even = n-1. Addition happens n-1/2 times. -1 happens n-1/2 times. 
        else
        {
            result += 1LL*m*((n-1)/2);
            result-=(n-1)/2;
            result++;
        }
        return result;
    }
};