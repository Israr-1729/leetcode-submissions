class Solution {
public:
    int sumOfNum(int num)
    {
        int ans = 0;
        while(num)
        {
            ans += num%10;
            num/=10;
        }
        return ans;
    }
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> mp;
        for(int i = lowLimit; i<=highLimit; i++)
        {
            mp[sumOfNum(i)]++;
        }

        int most = INT_MIN;
        for(auto &a : mp)
        {
            most = max(most, a.second);
        }
        
        return most;
    }
};