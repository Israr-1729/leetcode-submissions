class Solution {
public:

    unordered_set<int> powers;

    void generator()
    {
        long long i = 1;
        while(i<INT_MAX)
        {
            powers.insert(i);
            i *= 2;
        }
    }
    bool isPowerOfTwo(int n) {
        generator();
        return powers.contains(n);
    }
};