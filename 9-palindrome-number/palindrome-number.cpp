class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0)
        return false;

        long long absx = (long long)x;
        absx = absx<0 ? -absx : absx;
        long long rev = 0;
        while(absx>0)
        {
            rev = rev*10 + absx%10;
            absx/=10;
        }
        return rev==x;

        



        
    }
};