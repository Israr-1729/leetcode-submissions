class Solution {
public:
    set<int> isSeen;
    bool isHappy(int n) {

        if(n==1)
        return true;

        if(isSeen.contains(n))
        return false;

        isSeen.insert(n);

        int summ = 0;

        while(n>0)
        {
            int digit = n%10;
            summ += digit*digit;

            n/=10;
        }
        
        return isHappy(summ);
    }
};