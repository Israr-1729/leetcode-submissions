class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int posn = i+1;
            int reversePosn = 'z' - s[i] + 1;

            sum += posn * reversePosn;
        }
        return sum;
    }
};