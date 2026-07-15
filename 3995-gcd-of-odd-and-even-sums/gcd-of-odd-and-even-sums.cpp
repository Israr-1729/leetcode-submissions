class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n*(n+1);

        for(int i = sumOdd; i>=1; i--)
        {
            if(sumOdd%i == 0 && sumEven%i == 0)
            return i;
        }
        return 1;
    }
};