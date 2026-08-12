class Solution {
public:
    bool isBalanced(string num) {
        int sumEven = 0;
        int sumOdd = 0;
        for(int i = 0; i<num.size(); i++)
        {
            if(i%2 == 0)
            sumEven += num[i] - '0';

            else
            sumOdd += num[i] - '0';
        }
        return sumEven == sumOdd;
    }
};