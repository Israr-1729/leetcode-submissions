class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> discount = prices;
        for(int i = 0; i < prices.size(); i++)
        {
            int idx = i+1; bool found = false;
            while(idx < prices.size())
            {
                if(prices[i] >= prices[idx])
                {
                    found = true;
                    break;
                }
                idx++;
            }
            if(found)
            {
                discount[i] -= prices[idx];
            }
        }
        return discount;
    }
};