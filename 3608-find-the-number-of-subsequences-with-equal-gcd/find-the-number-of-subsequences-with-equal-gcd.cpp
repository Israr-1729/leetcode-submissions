#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int imposs=201;
    int _gcd(int x, int y) {
        if(x==imposs) return y;
        if(y==0) return x;
        return _gcd(y, x%y);
    }

    int dp[210][210][210];
    int n;
    int rec(int lev, int gcd1, int gcd2, vector<int>& nums) {
        if(lev==n) {
            if(gcd1==imposs || gcd2==imposs) return 0;
            return ((gcd1==gcd2) ? 1 : 0);
        }

        if(dp[lev][gcd1][gcd2]!=-1) return dp[lev][gcd1][gcd2];

        ll ans=0;
        ans += rec(lev+1, _gcd(gcd1, nums[lev]), gcd2, nums);     
        ans += rec(lev+1, gcd1, _gcd(gcd2, nums[lev]), nums);    
        ans += rec(lev+1, gcd1, gcd2, nums);                   

        return dp[lev][gcd1][gcd2] = ans%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, imposs, imposs, nums);
    }
};