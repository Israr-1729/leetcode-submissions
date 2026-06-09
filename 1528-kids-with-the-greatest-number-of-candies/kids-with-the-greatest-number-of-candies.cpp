class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxm = INT_MIN;
        int size = candies.size();
        for(int i = 0; i<size; i++)
        {
            maxm = max(maxm, candies[i]);
        }
        vector<bool> result(size, false);
        for(int i = 0; i<size; i++)
        {
            if(candies[i]+extraCandies>=maxm)
            result[i] = true;;
        }
        return result;
    }
};