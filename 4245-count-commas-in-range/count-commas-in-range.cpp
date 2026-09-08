class Solution {
public:
    int counter(int i)
    {
        int ans = 0;
        while(i)
        {
            i /= 1000;
            if(i != 0)
            ans++;
        }
        return ans;
    }
    int countCommas(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += counter(i);
        }
        return ans;
    }
};