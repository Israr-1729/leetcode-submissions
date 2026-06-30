class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> freq;
        while(n>0)
        {
            freq[n%10]++;
            n/=10;
        }

        int leastFrequency = INT_MAX;
        int least = 0;
        
        for(auto &p : freq)
        {
            if(p.second<=leastFrequency)
            {
                if(p.second<leastFrequency)
                {
                    least = p.first;
                    leastFrequency = p.second;
                }

                else
                {
                    least = min(least, p.first);
                }
            }
        }
        return least;
    }
};