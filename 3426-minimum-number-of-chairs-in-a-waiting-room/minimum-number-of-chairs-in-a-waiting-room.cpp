class Solution {
public:
    int minimumChairs(string s) {
        int maxm = INT_MIN;
        int curr = 0;
        for(char c : s)
        {
            if(c == 'E')
            curr++;

            else if(c == 'L')
            curr--;

            maxm = max(maxm, curr);
        }
        return maxm;
    }
};