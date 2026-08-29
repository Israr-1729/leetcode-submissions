class Solution {
public:
    vector<int> factorials;
    void fillFactorials()
    {
        factorials.push_back(1);
        int runningProduct = 1;
        for(int i = 1; i <= 9; i++)
        {
            runningProduct *= i;
            factorials.push_back(runningProduct);
        }
        return;
    }

    vector<int> frequencer(int n)
    {
        vector<int> freq(26, 0);
        while(n)
        {
            freq[n%10]++;
            n/=10;
        }
        return freq;
    }
    bool isDigitorialPermutation(int n) {
        fillFactorials();
        int copy = n;
        int runningSum = 0;
        while(copy)
        {
            runningSum += factorials[copy%10];
            copy/=10;
        }
        return frequencer(runningSum) == frequencer(n);
    }
};