class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        //Stores frequency of all numbers
        unordered_map<int, int> freq;
        for(int a : nums)
        freq[a]++;


        //Stores frequency of frequency
        unordered_map<int, int> freqfreq;
        for(auto &p : freq)
        {
            freqfreq[p.second]++;
        }

        //Stores if a certain frequency is unique
        unordered_map<int, bool> uniqueFrequency;
        for(auto &p : freqfreq)
        {
            if(p.second==1)
            {
                uniqueFrequency[p.first] = true;
            }
        }

        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            if(uniqueFrequency[freq[nums[i]]])
            return nums[i];
        }
    return -1;
    }
};