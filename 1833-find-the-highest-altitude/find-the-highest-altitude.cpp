class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current = 0;
        int highest = 0;
        for(int a : gain)
        {
            current += a;
            highest = max(current, highest);
        }
        return highest;
    }
};