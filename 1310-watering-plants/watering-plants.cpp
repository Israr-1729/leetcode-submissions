class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int size = plants.size();
        int i = 0;
        int currentFill = capacity;

        while(i<size)
        {
            while(i<size && currentFill>=plants[i])
            {
                currentFill-=plants[i];
                i++;
                steps++;
            }
            
            if(i<size)
            {
                currentFill = capacity;
                steps += 2*i;
            }
        }
        return steps;
    }
};