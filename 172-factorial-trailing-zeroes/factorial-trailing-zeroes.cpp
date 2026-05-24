class Solution {
public:
    int trailingZeroes(int n) {
        int i = 1;
        int numberOfZeroes = 0;
        while(n/(int)pow(5,i) != 0)
        {
            numberOfZeroes += (n/((int)(pow(5,i))));
            i++;
        }
        return numberOfZeroes;
        
    }
};