class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits(10, 0);
        while(n)
        {
            digits[n%10]++;
            n/=10;
        }

        int product = 1; int count = 0;
        for(int i = 9; i>=0; i--)
        {
            while(digits[i]!=0)
            {
                product*=i;
                count++;
                digits[i]--;

                if(count==2)
                break;
            }
            if(count == 2)
            break;
        }
        return product;
    }
};