class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int smallestManhattanDistance = INT_MAX;
        int ans = -1;
        for(auto i = 0; i < drones.size(); i++)
        {
            const vector <int> &a = drones[i];
            int manhattanDistance = (abs(target[0]-a[0])+ abs(target[1]-a[1]));
            if(manhattanDistance <= a[2] && manhattanDistance <= smallestManhattanDistance)
            {
                if(manhattanDistance == smallestManhattanDistance)
                continue;

                ans = i;
                smallestManhattanDistance = manhattanDistance;
            }
        }
        return ans;
    }
};