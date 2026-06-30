class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int a : nums)
        {
            freq[a]++;
        }

        int sum = 0;
        for(int a : nums)
        {
            if(freq[a]%k==0)
            sum += a;
        }
        return sum;
    }
};