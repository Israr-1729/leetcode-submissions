class Solution {
public:
    int maxPower(string s) {
        int size = s.size();
        int i = 0;
        int maxPower = 1;
        while(i<size)
        {
            int power = 1;
            while(i<size-1 && s[i]==s[i+1])
            {
                power++;
                i++;
            }
            maxPower = max(power, maxPower);
            i++;
        }
        return maxPower;
    }
};