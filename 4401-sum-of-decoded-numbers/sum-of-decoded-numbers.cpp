class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;
    long long modPow(long long x, long long y) {
        long long result = 1;

        x %= MOD;

        while (y > 0) {
            if (y & 1)
                result = result * x % MOD;

            x = x * x % MOD;
            y >>= 1;
        }

        return result;
    }
    long long decoder(long long i) {
        int width = i % 10;
        string d = to_string(1LL * i / 10);

        long long x = stoll(d.substr(0, width));
        long long y = stoll(d.substr(width, d.size() - width));

        return modPow(x, y);
    }
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        for (long long& i : nums) {
            sum = (sum + decoder(i)) % MOD;
        }
        return sum;
    }
};