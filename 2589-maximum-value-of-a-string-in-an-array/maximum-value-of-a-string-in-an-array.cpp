class Solution {
public:
    bool digitOnly(const string &s)
    {
        for(char c : s)
        {
            if(!isdigit(c))
            return false;
        }
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int maxValue = 0;
        for(auto &a : strs)
        {
            if(digitOnly(a))
            maxValue = max(maxValue, stoi(a));

            else
            maxValue = max(maxValue, (signed)a.size());
        }
        return maxValue;
    }
};