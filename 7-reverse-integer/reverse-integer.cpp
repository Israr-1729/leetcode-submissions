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

        if(rev>INT_MAX || rev<INT_MIN)
        rev = 0;

        if(x<0)
        return -1*rev;
        else
        return rev;
        
    }
};