class Solution {
public:
    bool checkPowersOfThree(int n) {

        if(n%3 != 0)
        n--;
        
        if(n==0)
        return true;

        if(n%3 != 0)
        return false;
        
        while(n%3==0)
        n/=3;

        return checkPowersOfThree(n);
        
    }
};