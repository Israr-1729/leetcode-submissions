class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int a : nums)
        {
            freq[a]++;
        }

        unordered_map<int, int> freqfreq;
        for(auto &a : freq)
        {
            freqfreq[a.second]++;
        }
        
        for(int a : nums)
        {
            if(freqfreq[freq[a]]==1)
            return a;
        }
        return -1;
    }
};