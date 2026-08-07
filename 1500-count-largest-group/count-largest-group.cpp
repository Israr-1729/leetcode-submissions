class Solution {
public:

    int sum(int num)
    {
        int ans = 0;
        while(num)
        {
            ans += num%10;
            num/=10;
        }
    return ans;
    }
    int countLargestGroup(int n) {

        unordered_map<int, int> sumToFreq;

        for(int i = 1; i<=n; i++)
        {
            sumToFreq[sum(i)]++;
        }

        int highest = INT_MIN;
        for(auto &a : sumToFreq)
        {
            highest = max(highest, a.second);
        }

        int ans = 0;
        for(auto &a : sumToFreq)
        {
            if(a.second == highest)
            ans++;
        }

        return ans;
    }
};