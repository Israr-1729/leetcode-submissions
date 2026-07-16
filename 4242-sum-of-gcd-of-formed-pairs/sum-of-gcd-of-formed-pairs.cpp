class Solution {
public:

    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


    vector<int> evenSize(const vector<int> &prefixGCD)
    {
        int size = prefixGCD.size();
        vector<int> result(size/2);

        for(int i = 0; i<size/2; i++)
        {
            result[i] = gcd(prefixGCD[i], prefixGCD[size-i-1]);
        }

        return result;
    }
    vector<int> oddSize(const vector<int> &prefixGCD)
    {
        int size = prefixGCD.size();
        vector<int> result((size-1)/2);

        for(int i = 0; i<(size-1)/2; i++)
        {
            result[i] = gcd(prefixGCD[i], prefixGCD[size-i-1]);
        }
        return result;
    }
    long long gcdSum(vector<int>& nums) {
        int size = nums.size();
        vector<int> maxmi(size);
        int currentMaxm = INT_MIN;
        for(int i = 0; i<size; i++)
        {
            currentMaxm = max(currentMaxm, nums[i]);
            maxmi[i] = currentMaxm;
        }

        vector<int>prefixGCD(size);

        for(int i = 0; i<size; i++)
        {
            prefixGCD[i] = gcd(nums[i], maxmi[i]);
        }

        sort(prefixGCD.begin(), prefixGCD.end()); 

        vector<int>GCDValuesOfPairs = (size % 2 == 0) ? evenSize(prefixGCD) : oddSize(prefixGCD);

        long long sum = 0;
        for(int a : GCDValuesOfPairs)
        {
            sum += a;
        }
        return sum;
    }
};