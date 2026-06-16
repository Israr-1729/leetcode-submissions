class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int size = costs.size();
        int sum = 0;
        int count = 0;
        for(int i = 0; i<size; i++)
        {
            if(sum + costs[i]>coins)
            break;
            else
            {
                sum += costs[i];
                count ++;
            }
        }
        return count;
    }
};