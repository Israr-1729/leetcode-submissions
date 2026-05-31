class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());
        int size = asteroids.size();
        long long sumTillAsteroid = mass;
        for(int i = 0; i<size; i++)
        {
            if(sumTillAsteroid>INT_MAX)
            return true;
            else if(sumTillAsteroid>=asteroids[i])
            {
                sumTillAsteroid += asteroids[i];
            }
            else
            return false;
        }
        return true;
    }
};