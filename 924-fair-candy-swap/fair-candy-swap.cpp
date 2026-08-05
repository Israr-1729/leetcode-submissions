class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long long totalAlice = 0;
        long long totalBob = 0;

        for(int a : aliceSizes)
        {
            totalAlice += a;
        }

        unordered_set<int> setBob;
        for(int a : bobSizes)
        {
            totalBob += a;
            setBob.insert(a);
        }

        int final = (totalAlice + totalBob)/2;

        for(int a : aliceSizes)
        {
            int aliceAfterGiven = totalAlice - a;
            int neededForFair = final - aliceAfterGiven;

            if(setBob.contains(neededForFair))
            return {a, neededForFair};
        }
        return {-1, -1};
    }
};