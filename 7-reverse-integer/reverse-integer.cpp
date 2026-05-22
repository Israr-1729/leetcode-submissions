class Solution {
public:
    int reverse(int x) {

        

        long long absx = x<0 ? -(long long)x : x;
        long long rev = 0;

        while(absx!=0)
        {
            rev = rev*10 + absx%10;
            absx/=10;
        }

        if(x<0)
        rev = -rev;

        if(rev>INT_MAX || rev<INT_MIN)
        rev = 0;
        
        return rev;
        
    }
};