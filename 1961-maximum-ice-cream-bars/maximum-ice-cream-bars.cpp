class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int size = costs.size();
        int count = 0;
        for(int i = 0; i<size; i++)
        {
            if(costs[i]>coins)
            break;
            else
            {
                count++;
                coins -= costs[i];
            }
        }
        return count;
    }
};