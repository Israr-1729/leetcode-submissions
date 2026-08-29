class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long option1 =
            (long long)cost1 * need1 +
            (long long)cost2 * need2;

        long long common = min(need1, need2);

        long long option2 =
            (long long)costBoth * common +
            (long long)cost1 * (need1 - common) +
            (long long)cost2 * (need2 - common);

        long long option3 =
            (long long)costBoth * max(need1, need2);

        return min({option1, option2, option3});
    }
};