class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)
        return false;
        int powerOf2 = 0;
        while(n%2==0)
        {
            n/=2;
            powerOf2++;
        }
        if(n != 1)
        return false;
        if(powerOf2%2 == 0)
        return true;
        return false;
    }
};