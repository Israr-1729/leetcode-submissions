class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long sum = 0;
        for(int a : cardPoints)
        sum += a;

        int windowSize = cardPoints.size()-k;
        if(windowSize == 0)
        return sum;
        int startingWindowSum = 0;
        for(int i = 0; i<windowSize; i++)
        {
            startingWindowSum += cardPoints[i];
        }

        int windowSizeMinimum = startingWindowSum;
        int currentWindowSum = startingWindowSum;
        int idx = 0;
        for(int i = windowSize-1, size = cardPoints.size(); i<size-1; i++)
        {

            currentWindowSum -= cardPoints[idx++];
            currentWindowSum += cardPoints[i+1];
            windowSizeMinimum = min(windowSizeMinimum, currentWindowSum);

        }
        return sum-windowSizeMinimum;
        
    }
};