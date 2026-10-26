class Solution {
public:

    long long binary(int n) {
    long long ans = 0, place = 1;

    while (n > 0) {
        ans += (n % 2) * place;
        n /= 2;
        place *= 10;
    }

    return ans;
}

    int score(long long a)
    {
        int ans = 0;
        while(a)
        {
            ans += a%10;
            a/=10;
        }
        return ans;
    }
    int calculateScore(int a, int b) {
        return score(binary(a)) >= score(binary(b)) ? score(binary(a)) * score(binary(b)) : score(binary(b))/score(binary(a));
    }
};