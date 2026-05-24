class Solution {
public:

    bool isPerfectSquare(int num) {
        int counter = 0;

        if(num==INT_MAX || num<0)
        return false;
        for(long long i = 1; i*i<=num; i++)
        {
            if(i*i == num)
            return true;
        }
        return false;
    }
};