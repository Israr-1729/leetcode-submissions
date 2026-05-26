class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        vector<int> twoMin (2,101);
        int size = prices.size();
        for(int i = 0; i<size; i++)
        {
            if(twoMin[0]>prices[i] && twoMin[1]>prices[i])
            {
                twoMin[1] = twoMin[0];
                twoMin[0] = prices[i];
            }

            else if(twoMin[1]>prices[i] && twoMin[0]<=prices[i])
            {
                twoMin[1] = prices[i];
            }
        }

        if(twoMin[0]+twoMin[1]<=money)
        return money - twoMin[0] - twoMin[1];
        else
        return money;
        
    }
};