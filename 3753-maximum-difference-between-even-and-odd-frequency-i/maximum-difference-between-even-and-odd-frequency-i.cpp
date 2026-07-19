class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for(char c : s)
        {
            freq[c]++;
        }

        int highestOdd = INT_MIN;
        int lowestEven = INT_MAX;
        for(auto &p : freq)
        {
            if(p.second % 2 == 1)
            {
                highestOdd = max(p.second, highestOdd);
            }
            
            else
            {
                lowestEven = min(p.second, lowestEven);
            }
        }
        return highestOdd - lowestEven;
    }
};