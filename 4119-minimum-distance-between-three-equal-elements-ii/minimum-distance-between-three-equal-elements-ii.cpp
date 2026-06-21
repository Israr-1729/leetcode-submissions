class Solution {
public:


    int minimumPower(vector<int>& arr)
    {
        int size = arr.size();
        int minPower = INT_MAX;
        for(int i = 1; i<size-1; i++)
        {
            int power = (arr[i+1]-arr[i]) + (arr[i+1]-arr[i-1]) + (arr[i]-arr[i-1]);
            minPower = min(power, minPower);
        }
        return minPower;
    }
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto &a : mp)
        {
            if(a.second.size()>=3)
            {
                int thisPower = minimumPower(a.second);
                ans = min(thisPower, ans);
            }
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};