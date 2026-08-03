class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int size = s.size();
        vector<int> result(size);

        vector<int> occurencesOfc;

        for(int i = 0; i<size; i++)
        {
            if(s[i] == c)
            occurencesOfc.push_back(i);
        }

        for(int i = 0; i<size; i++)
        {
            int distance;
            int closestDistance = INT_MAX;
            for(int a : occurencesOfc)
            {
                distance = abs(a-i);
                closestDistance = min(distance, closestDistance);
            }
            result[i] = closestDistance;
            }
    return result;
    }
};