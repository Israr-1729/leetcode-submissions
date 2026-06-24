class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int a : nums)
        {
            mp[a]++;
        }

        int x = -1; int f = -1;
        for(auto &a : mp)
        {
            if(a.second>f)
            {
                f = a.second;
                x = a.first;
            }
        }

        if(f*2<=nums.size())
        return -1;

        int size = nums.size();
        int freqTillNow = 0;

        vector<int> dominantPrefix(size);
        for(int i = 0; i<size; i++)
        {
            if(nums[i]==x)
            freqTillNow++;
            dominantPrefix[i] = freqTillNow;
        }

        freqTillNow = 0;
        vector<int> dominantSuffix(size);
        for(int i = size-1; i>=0; i--)
        {
            if(nums[i]==x)
            freqTillNow++;
            dominantSuffix[i] = freqTillNow; 
        }

        for(int i = 0; i<size-1; i++)
        {
            if(dominantPrefix[i]*2>i+1 && dominantSuffix[i+1]*2>(size-i-1))
            return i;
        }
        return -1;
    }
};