class Solution {
public:


    bool isPerfectSquare(int n) 
    {
    if (n < 0) return false;  
    int root = sqrt(n);
    return root * root == n;
    }
    int bulbSwitch(int n) {
        int count = 0;
        for(int i = 1; i<=n; i++)
        {
            if(isPerfectSquare(i))
            count++;
        }
        return count;
    }
};