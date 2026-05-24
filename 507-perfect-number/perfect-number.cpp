class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0; //sum of divisors
        if(num==1)
        return false;
        for(int i = 2; i*2<=num; i++)
        {
            if(num%i == 0)
            sum +=i;
        }
        return (sum+1 == num);
        
    }
};