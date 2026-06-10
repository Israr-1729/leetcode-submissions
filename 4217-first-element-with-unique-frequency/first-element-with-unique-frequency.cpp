class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int a : nums)
        freq[a]++;
        unordered_map<int, int> freqfreq;
        for(auto &p : freq)
        {
            freqfreq[p.second]++;
        }
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            if(freqfreq[freq[nums[i]]]==1)
            return nums[i];
        }
    return -1;
    }
};