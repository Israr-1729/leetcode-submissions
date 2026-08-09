class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        reverse(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());
        reverse(discounts.begin(), discounts.end());

        double minPrice = 0;
        int idx = 0;

        for(idx = 0; idx<discounts.size(); idx++)
        {
            if(idx >= prices.size())
            break;
            minPrice += prices[idx] - discounts[idx] * (prices[idx] / 100.0);
        }

        if(idx < prices.size())
        {
            for(int i = idx; i<prices.size(); i++)
            minPrice += prices[i];
        }
        
        return minPrice;
    }
};