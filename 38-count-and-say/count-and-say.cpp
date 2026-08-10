class Solution {
public:
    string countAndSay(int n) {

        if(n == 1)
        return "1";

        string num = countAndSay(n-1);
        int i = 0;
        vector<pair<int, int>> RLENotation;
        while(i < num.size())
        {
            int newDigit = num[i] - '0';
            int freq = 0;

            while(i < num.size() && num[i] == newDigit + '0')
            {
                i++;
                freq++;
            }

            RLENotation.push_back({freq, newDigit});
        }

        string result = "";

        for(auto &v : RLENotation)
        {
            result += (to_string(v.first));
            result += (to_string(v.second));
        }
        
        return result;
    }
};