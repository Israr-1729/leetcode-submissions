class Solution {
public:

    long long product(int num) {
        long long result = 1;
        while(num)
        {
            result *= num%10;
            num/=10;
        }
        return result;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i>0; i++)
        {
            if(product(i)%t == 0)
            return i;
        }
        return -1;
    }
};