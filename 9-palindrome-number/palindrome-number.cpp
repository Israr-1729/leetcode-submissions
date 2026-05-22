class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0)
        return false;
        int absx = x;
        long long rev = 0;
        while(absx>0)
        {
            rev = rev*10 + absx%10;
            absx/=10;
        }
        return rev==x;
        
    }
};