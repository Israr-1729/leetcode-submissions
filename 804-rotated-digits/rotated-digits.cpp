class Solution {
public:
    bool isValidAndChanged(int n)
    {
        bool isChanged = false;
        while(n>0)
        {
            int digit = n%10;
            if(digit == 3 || digit == 4 || digit == 7)
            return false;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9)
            isChanged = true;
            n/=10;
        }
        return isChanged;
    }

    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i++)
        {
            if(isValidAndChanged(i))
            ans++;
        }
        return ans;
    }
};