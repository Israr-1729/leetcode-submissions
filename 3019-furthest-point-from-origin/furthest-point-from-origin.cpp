class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0; 
        int dashCount = 0;
        for(char c : moves)
        {
            if(c == 'L')
            left++;

            if(c == 'R')
            left--;

            if(c == '_')
            dashCount++;
        }
        if(left < 0)
        left -= dashCount;

        if(left >= 0)
        left += dashCount;

        return abs(left);
    }
};