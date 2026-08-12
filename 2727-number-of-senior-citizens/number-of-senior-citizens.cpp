class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto &s : details)
        {
            if((s[11] == '6' && s[12] != '0') || s[11] > '6') 
            count++;
        }
        return count;
    }
};