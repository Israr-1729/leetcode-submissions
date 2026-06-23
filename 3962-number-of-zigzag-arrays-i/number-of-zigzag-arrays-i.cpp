const int MOD = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if(m == 1)
            return 0;
        if(n == 1)
            return m % MOD;
        vector<long long> up(m+1, 0), down(m+1, 0);
        for(int i=1; i<=m; i++){
            up[i] = i - 1;
            down[i] = m - i;
        }
        vector<long long> preUp(m+1, 0), preDown(m+1, 0);
        vector<long long> up_next(m+1, 0), down_next(m+1, 0);
        for(int len=3; len<=n; len++){
            for(int i=1; i<=m; i++){
                preUp[i] = (preUp[i-1] + up[i]) % MOD;
                preDown[i] = (preDown[i-1] + down[i]) % MOD;
            }
            for(int i=1; i<=m; i++){
                up_next[i] = preDown[i-1] % MOD;
                down_next[i] = (preUp[m] - preUp[i] + MOD) % MOD;
            }
            up = up_next;
            down = down_next;
        }
        long long ans = 0;
        for(int i=1; i<=m; i++)
            ans = (ans + up[i] + down[i]) % MOD;
        return ans;
    }
};