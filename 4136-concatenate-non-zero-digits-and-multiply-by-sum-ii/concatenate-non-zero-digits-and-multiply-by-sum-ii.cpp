class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;

        int n = s.size();

        vector<int> prefSum(n + 1, 0);

        vector<int> pos;
        vector<int> digit;

        for(int i = 0; i < n; i++)
        {
            int d = s[i] - '0';
            prefSum[i + 1] = prefSum[i] + d;

            if(d)
            {
                pos.push_back(i);
                digit.push_back(d);
            }
        }

        int m = digit.size();

        vector<long long> prefNum(m + 1, 0);
        vector<long long> power(m + 1, 1);

        for(int i = 0; i < m; i++)
        {
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % mod;
            power[i + 1] = (power[i] * 10) % mod;
        }

        vector<int> result;

        for(auto &q : queries)
        {
            int l = q[0], r = q[1];

            int sum = prefSum[r + 1] - prefSum[l];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if(it1 == it2)
            {
                result.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = it2 - pos.begin() - 1;

            long long x = (prefNum[R + 1] - prefNum[L] * power[R - L + 1]) % mod;
            if(x < 0) x += mod;

            result.push_back(1LL * sum * x % mod);
        }

        return result;
    }
};