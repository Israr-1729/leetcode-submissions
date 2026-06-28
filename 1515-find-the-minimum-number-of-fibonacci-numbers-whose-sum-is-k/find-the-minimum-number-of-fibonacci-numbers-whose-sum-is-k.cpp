class Solution {
public:
    vector<int> fibs;

    void generateFibonacciNumbers(int k, vector<int> &fibs)
    {
        vector<int> pair(2);
        pair[0] = 0;
        pair[1] = 1;
        while(pair[1]<=k)
        {
            int sum = pair[0] + pair[1];
            pair[0] = pair[1];
            pair[1] = sum;
            fibs.push_back(pair[1]);
        }
        return;
    }
    int findMinFibonacciNumbers(int k) {
        generateFibonacciNumbers(k, fibs);
        int ans = 0;
        reverse(fibs.begin(), fibs.end()); int size = fibs.size();
        for(int i = 0; i<size; i++)
        {
            if(fibs[i]<=k)
            {
                ans++;
                k-=fibs[i];
            }

        }
        return ans;
    }
};