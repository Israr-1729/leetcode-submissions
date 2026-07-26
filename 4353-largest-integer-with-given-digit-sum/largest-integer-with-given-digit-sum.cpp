class Solution {
public:

    int digitSum(int n)
    {
        int result = 0;
        while(n)
        {
            result += n%10;
            n/=10;
        }
        return result;
    }

    int largestInteger(int n, int s) {
        int num = 0;

        if(s==0)
        return 0;

        for(int i = 0; i<n; i++)
        {
            num = num*10 + 9;
        }

        while(true)
        {
            if(digitSum(num) == s)
            break;

            if(num<0)
            return -1;

            num--;
        }
        return num;
    }
};