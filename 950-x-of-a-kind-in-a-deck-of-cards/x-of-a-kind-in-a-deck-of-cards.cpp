class Solution {
public:

    bool leastFrequencyDivisible(vector<int> &deck) {
        unordered_map<int, int> mp;
        for(int a : deck)
        {
            mp[a]++;
        }

        int leastFreq = INT_MAX;
        for(auto &a : mp)
        {
            if(a.second < leastFreq)
            leastFreq = a.second;
        }

        if(leastFreq == 1)
        return false;

        for(auto &a : mp)
        {
            if(gcd(leastFreq, a.second) == 1)
            return false;

            if(gcd(leastFreq, a.second) < leastFreq)
            leastFreq = gcd(leastFreq, a.second);
        }
        return true;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        return leastFrequencyDivisible(deck);
    }
};