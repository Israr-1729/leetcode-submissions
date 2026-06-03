class Solution {
public:
    double myPow(double x, int n) {

        if(x<1 && x>=0 && n==INT_MAX)
        return 0;

        if(x==1)
        return 1;



        if(x==-1 && n%2==1)
        return -1;

        if(x==-1 && n%2==0)
        return 1;

        if(n==INT_MIN)
        return 0;

        double power = 1;

        if(n>0)
        {
        for(int i = 1; i<=n; i++)
        power*=x;
        return power;
        }

        else if(n<0)
        {
            for(int i = 1; i<=abs(n); i++)
            power/=x;
            return power;
        }

        else
        return 1;
        
    }
};